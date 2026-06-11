#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
#define int long long
int INF = 1e9+7;
signed main() {
    int N;
    string S;
    cin >> N >> S;
    int r = 0;
    int g = 0;
    int b = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'R') {
            r++;
        }
        else if(S[i] == 'G') {
            g++;
        }
        else {
            b++;
        }
    }
    int ans = r*g*b;
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            int k = j+(j-i);
            if(k >= N) {
                continue;
            }
            if(S[i] != S[j] && S[j] != S[k] && S[i] != S[k]) {
                ans--;
            }
        }
    }
    cout << max(0LL,ans) << endl;
}