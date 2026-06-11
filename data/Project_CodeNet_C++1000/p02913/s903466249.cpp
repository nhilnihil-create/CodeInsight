#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, ans=0, tmp=0;
vector<ll> A(MAXN, 0);
string S;

signed main(){
    cin >> N >> S;
    ll DP[N+1][N+1]={{0}};
    for(int i=N-1;i>=0;i--) {
        for(int j=N-1;j>=0;j--) {
            if(S[i]==S[j]) {
                DP[i][j]=min(abs(i-j), DP[i+1][j+1]+1);
                ans = max(ans, DP[i][j]);
            }
            else DP[i][j]=0;
        }
    }
    cout << ans << endl;
    return 0;
}