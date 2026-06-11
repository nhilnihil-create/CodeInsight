/*
 * author :Sadik Hassan
 *
*/
#include "bits/stdc++.h"
using namespace std;
using   ll =          long long;
#define nl            "\n"
#define pb            push_back
#define fi            first
#define se            second
#define PI            (acos(-1.0))
#define repp(i,a,n)   for(int i=a;i<n;i++)
#define rep(i,n)      for(int i=0;i<n;i++)
#define SZ(s)         s.size()
#define SRT(x,y)      sort(x,x+y)
#define REV(a,b)      reverse(a,a+b)
#define VSRT(x)       sort(x.begin(),x.end())
#define VREV(x)       reverse(x.begin(),x.end())
#define w(t)          int t;cin>>t;while(t--)
#define TSFL(s)       transform(s.begin(),s.end(),s.begin(),::toupper);
#define TSFH(s)       transform(s.begin(),s.end(),s.begin(),::tolower);
#define _SAD()        ios::sync_with_stdio(0),cin.tie(0), cout.tie(0),cout<<fixed<<setprecision(15);
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
    int h1,m1,h2,m2,k;
    cin>>h1>>m1>>h2>>m2>>k;
    int cnt=0;
    while(1)
    {
        if(h1==h2&&m2==m1)break;
        m1++;
        cnt++;
        if(m1==60)
        {
            m1=0;
            h1++;
        }
    }
    cout<<max(0,cnt-k)<<nl;
    return 0;
}
