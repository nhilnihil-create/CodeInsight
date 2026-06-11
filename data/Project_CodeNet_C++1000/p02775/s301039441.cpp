#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define all(ppp) ppp.begin(),ppp.end() 

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define pb push_back

typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<string> vs;
int dp[2][1500000];
int main(){
    string S;
    cin>>S;
    dp[0][0]=S[0]-'0';
    dp[1][0]=11-(S[0]-'0');
    for(int i=1;i<S.length();i++){
        dp[0][i]=min(dp[0][i-1],dp[1][i-1])+(S[i]-'0');
        dp[1][i]=min(dp[0][i-1]+11-(S[i]-'0'),dp[1][i-1]+9-(S[i]-'0'));
    }
    cout<<min(dp[0][S.size()-1],dp[1][S.size()-1])<<endl;
    return 0;

    return 0;
}
