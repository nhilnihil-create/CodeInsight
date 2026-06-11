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
    if(S == INF) {
        for(int i = 0; i < N; i++) {
            if(i) {
                cout << " ";
            }
            if(i < K) {
                cout << S;
            }
            else {
                cout << 1;
            }
        }
        cout << endl;
    }
    else {
        for(int i = 0; i < N; i++) {
            if(i) {
                cout << " ";
            }
            if(i < K) {
                cout << S;
            }
            else {
                cout << INF;
            }
        }
        cout << endl;
    }
}
