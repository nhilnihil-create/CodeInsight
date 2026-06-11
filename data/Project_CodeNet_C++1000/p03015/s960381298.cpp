#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, ans=0, tmp=0;
vector<ll> A(MAXN, 0);
string S;
signed main(){
    cin >> S;
    vector<ll> dp1(S.size()+1,1), dp2(S.size()+1,0);
    for(int i=1;i<=S.size();i++) {
        if(S[i-1]=='0') {
            dp1[i] = dp1[i-1];
            dp2[i] = 3*dp2[i-1];
            dp2[i] %= 1000000007;
        }
        else {
            dp1[i] = 2*dp1[i-1];
            dp1[i] %= 1000000007;
            dp2[i] = 3*dp2[i-1]+dp1[i-1];
            dp2[i] %= 1000000007;
        }
    }
    //cout << dp1[S.size()] << " " << dp2[S.size()] << endl;
    cout << (dp1[S.size()]+dp2[S.size()])%1000000007 << endl;
    return 0;
}