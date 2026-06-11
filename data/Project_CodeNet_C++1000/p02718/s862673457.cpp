#include<iostream>
#include<cmath>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<climits>
#include<deque>
#include<tuple>
#include<iomanip>
using namespace std;
#define int                  int64_t
#define double               long double
#define vi                   vector<int>
#define di                   deque<int>
#define si                   set<int>
#define vpii                 vector<pair<int,int>>
#define pi                   pair<int,int>
#define pub                  push_back
#define puf                  push_front
#define pob                  pop_back
#define pof                  pop_front
#define all(a)               (a).begin(),(a).end()
#define rall(a)              (a).rbegin(),(a).rend()
#define PI                   3.1415926535897932384626433832795
#define read(a)              for(auto& x:a) cin>>x
#define speak(a)             for(auto x:a) cout<<x<<' '
#define rep(i,s,n)           for(int i=s;i<n;++i)
#define repe(i,s,n)          for(int i=s;i<=n;++i)
#define repr(i,n,s)          for(int i=n;i>=s;--i)
#define endl                 '\n'
#define gap                  ' '
#define MAX                  LLONG_MAX
#define MIN                  LLONG_MIN
#define min3(a,b,c)          min(a, min(b, c))
#define max3(a,b,c)          max(a, max(b, c))
#define MOD                  1000000007
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,c=0;
    double m;cin>>n>>m;
    double a[n],s=0; rep(i,0,n) cin>>a[i],s+=a[i];
    double ans=s/(4*m);
    rep(i,0,n) c+=(a[i]>=ans);
    cout<<(c>=m?"Yes":"No");
}
