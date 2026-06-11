#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, ans=0, tmp=0, DP[100005][13]={{0}};
string S;

signed main(){
    cin >> S;
    DP[0][0]=1;
    for(int i=1;i<=S.size();i++) {
        if(S[i-1]=='?') {
            for(int l=0;l<10;l++) {
                for(int j=0;j<13;j++) {
                    DP[i][(10*j+l)%13] += DP[i-1][j];
                    DP[i][(10*j+l)%13] %= 1000000007;
                }
            }
        }
        else {
            ll num = S[i-1]-'0';
            for(int j=0;j<13;j++) {
                DP[i][(10*j+num)%13] = DP[i-1][j];
            }
        }
    }
    cout << DP[S.size()][5] << endl;
    return 0;
}