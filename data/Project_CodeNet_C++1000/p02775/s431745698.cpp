#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, ans=0, tmp=0;
string S;
vector<vector<ll>> DP;

signed main(){
    cin >> S;
    //cout << S << endl;
    S = '0'+S;
    //cout << S << endl;
    DP.resize(1000005);
    for(int i=0;i<1000005;i++) {
        DP[i].resize(2,INF);
    }
    DP[0][0] = 0;
    for(int i=0;i<S.size();i++) {
        ll num = S[S.size()-1-i]-'0';
        for(int j=0;j<2;j++) {
            num += j;
            DP[i+1][0] = min(DP[i+1][0],DP[i][j]+num);
            DP[i+1][1] = min(DP[i+1][1],DP[i][j]+10-num);
        }
    }
    //cout << DP[1][0] << endl;
    cout << DP[S.size()][0] << endl;
    return 0;
}