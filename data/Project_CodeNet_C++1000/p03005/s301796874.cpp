/*
 * author :Sadik Hassan
 *
*/
#include "bits/stdc++.h"
using namespace std;
#define ll            long long
#define nl            "\n"
#define PB            push_back
#define fi            first
#define se            second
#define _SAD()        ios::sync_with_stdio(0),cin.tie(0), cout.tie(0);
#define rep(i,n)      for(int i=0;i<n;i++)
#define repn(i,n)     for(int i=1;i<=n;i++)
#define rrep(i,n)     for(int i=n-1;i>=0;i--)
#define SZ(s)         s.size()
#define SRT(x,y)      sort(x,x+y)
#define REV(a,b)      reverse(a,a+b)
#define VSRT(x)       sort(x.begin(),x.end())
#define VREV(x)       reverse(x.begin(),x.end())
#define TSFL(s)       transform(s.begin(),s.end(),s.begin(),::toupper);
#define TSFH(s)       transform(s.begin(),s.end(),s.begin(),::tolower);
/*---------------------------------------------------------------------*/
const int N = 2e5+10;
const int INF = (int)1e9+5;

int main()
{
    _SAD()
    int a,b;
    cin>>a>>b;
    cout<<a%b<<nl;
    return 0;
}
