#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1100000;
vector<int> cnt; // cnt[n] := how many times n! can be divided by 2
void pre() {
    cnt.assign(MAX, 0);
    for (int i = 1; i <= MAX; i++) {
        int n = i;
        int count = 0;
        while(n % 2 == 0) {
            count ++;
            n /= 2;
        }
        cnt[i] = cnt[i-1] + count;
    }
} 

int main(){ 
    pre();
    int N; cin >> N;
    vector<int> x(N);
    bool one = false;
    for (int i = 0; i < N; i++) {
        char a; cin >> a;
        x[i] = (a-'0')-1;
        if (x[i] == 1) one = true;
    }
    //x[0] is a vector conprised of only 0, 1, or 2.
    //until i = N, x[i] is conprised of only 0, 1, 2.
    // 偶奇判定
    int res = 0;
    for (int i = 0; i < N; i++) {
        int mod_comb = cnt[N-1] - cnt[N-1-i] - cnt[i];
        if (mod_comb > 0) continue;
        res += x[i];
    }

    if (res % 2 == 1) {
        cout << 1 << endl;
    }
    else {
        if (one) cout << 0 << endl;
        else {
            for (int i = 0; i < N; i++) {
                x[i] /= 2; 
            }
            res = 0;
            for (int i = 0; i < N; i++) {
                int mod_comb = cnt[N-1] - cnt[N-1-i] - cnt[i];
                if (mod_comb > 0) continue;
                res += x[i];
            }
            if (res % 2 == 1) cout << 2 << endl;
            else cout << 0 << endl;
        }
    }
}