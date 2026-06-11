#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
const int INF = 100000;

int get_times(int x){
    int times = 0;
    while(x > 0 && x % 2 == 0){
        times++;
        x /= 2;
    }
    return times;
}

// x = i/W, y = i%W;
// xy = j * W + i;
int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    string S;
    cin >> S;
    int only02flag = 1;
    rep(i, N){
        B[i] = S[i] - '1';
        if (B[i] == 1){
           only02flag = 0;
        }
    }

    rep(i, N){
        if (B[i] == 2){
            if (only02flag){
                B[i] = 1;
            } else {
                B[i] = 0;
            }
        }
    }
    
    int ans = 0;
    int times = 0;
    int nCk = 1;
    rep(i, N){
        if (i >= 1){
            times += get_times(N -i);
            times -= get_times(i);
            nCk *= (N - i);
            nCk /= i;
        }
        if (times == 0){
            ans ^= B[i];
        }
        //cout << i << " " << N + 1 - i << " " << nCk << " " << times << endl;
    }
    if (only02flag){
        cout << ans * 2;
    } else {
        cout << ans;
    }

    return 0;
}
