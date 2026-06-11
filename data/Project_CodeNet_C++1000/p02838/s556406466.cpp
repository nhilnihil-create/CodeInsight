#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 ,-1};
signed main(){
    int N;
    cin >> N;
    vector<int>A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int cnt = 1;
    int ans = 0;
    for(int i = 0; i < 60; i++) {
        int X = 0,Y = 0;
        for(int j = 0; j < N; j++) {
            if(1 & (A[j] >> i)) {
                X++;
            }
            else {
                Y++;
            }
        }
        ans+=X*Y%INF*cnt%INF;
        cnt = cnt*2%INF;
        ans%=INF;
    }
    cout << ans << endl;
}