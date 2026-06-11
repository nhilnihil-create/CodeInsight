#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,K,S;
    cin >> N >> K >> S;
    for(int i = 0; i < N; i++) {
        if(i < K) {
            cout << S;
        }
        else {
            if(S == INF) {
                cout << 1;
            }
            else {
                cout << INF;
            }
        }
        if(i+1 != N) {
            cout << " ";
        }
    }
}