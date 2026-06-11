#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,n) for(int i=a;i<(n);i++)
#define REP_sz(i,s) for(int i=0;i<s.size();i++)
#define RE return
#define FILL(a,b) memset(a,b,sizeof(a))
#define SO(a) sort(all(a))
#define pb push_back
#define sz(a) a.size()
#define V vector
#define ld long double
#define viit(a) vector<int>::iterator a
#define msit1(a) map<string,int>::iterator a
#define miit(a) map<int,int>::iterator a
#define msit2(a) map<int,string>::iterator a
#define IT iterator
#define FOR(i,a,n) for(int i=a;i<=(n);i++)
#define B(s) s.back()
#define all(a) a.begin(),a.end()
#define ER1(a) a.erase(a.begin())
#define ER0(a) a.erase(a.end())
#define pii pair<int,int>
#define pause system("PAUSE")
#define cls system("CLS")
using namespace std;
signed main() {
    ll n, m; cin >> n >> m;
    ll mod = 1000000007;
    int a[100003];
	FILL(a,0);
    REP(i,0,m) {
        int tmp; 
		cin>>tmp;
        a[tmp]=1;
    }
    int dp[100003]; 
    FILL(dp,0);
    dp[n] = 1;
    for(int i=n-1;i>=0;i--) {
        if (a[i] == 1) {
            continue;
        }
        dp[i]=0;
        dp[i]+=dp[i+1];
        dp[i]+=dp[i+2];
        dp[i]%=mod;
    }
    cout<<dp[0]<<endl;
    return 0;
}