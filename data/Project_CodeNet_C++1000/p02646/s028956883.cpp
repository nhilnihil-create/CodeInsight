/*
 * author :Sadik Hassan
 *
*/
#include "bits/stdc++.h"
using namespace std;
#define ll            long long
#define nl            "\n"
#define pb            push_back
#define fi            first
#define se            second
#define PI            (acos(-1.0))
#define _SAD()        ios::sync_with_stdio(0),cin.tie(0), cout.tie(0),cout<<fixed<<setprecision(20);
#define rep(i,n)    for(int i=0;i<n;i++)
#define SZ(s)         s.size()
#define SRT(x,y)      sort(x,x+y)
#define REV(a,b)      reverse(a,a+b)
#define VSRT(x)       sort(x.begin(),x.end())
#define VREV(x)       reverse(x.begin(),x.end())
#define w(t)          int t;cin>>t;while(t--)
#define TSFL(s)       transform(s.begin(),s.end(),s.begin(),::toupper);
#define TSFH(s)       transform(s.begin(),s.end(),s.begin(),::tolower);
typedef vector<int> vi;
typedef vector<ll> vii;
typedef set<int> si;
typedef set<ll> sii;
/*---------------------------------------------------------------------*/

const int N = 2e5+10;
const int INF = (int)1e9+5;

int main()
{
    _SAD()
	int a,b,m,n,t;
	cin>>a>>m>>b>>n>>t;
	a=abs(a-b);m-=n;
	if(m<=0)cout<<"NO";
	else if((a+m-1)/m<=t)cout<<"YES";
	else cout<<"NO";
    return 0;
}
