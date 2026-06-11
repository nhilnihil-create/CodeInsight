#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    int N,M; cin >> N >> M;
    const int INF = 1e9;
    ll height[N+10];
    vector<ll> matrix(N+10,-1);
    for(int i=1; i<=N; i++) cin >> height[i];
    for(int i=1; i<=M; i++) {
        int a,b; cin >> a >> b;
        int c; //低いほうの番号
        if(height[a]>=height[b]) {
            c = b;
            matrix[c] = INF;
        }
        if(height[a]<=height[b]) {
            c = a;
            matrix[c] = INF;
        }
    }
    int ans = 0;
    for(int i=1; i<=N; i++) {
        if(matrix[i] == -1) ans++;
    }
    cout << ans << endl;
}