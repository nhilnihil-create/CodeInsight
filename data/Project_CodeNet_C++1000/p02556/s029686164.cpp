#include<bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef double db;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector< pair<int,int> > vii;
const double pi = 2*acos(0) ;

#define pf		  	 printf
#define sf			 scanf
#define pb(a)        push_back(a)
#define mp			 make_pair
#define ff			 first
#define ss			 second
#define for0(i,n)    for(int i=0;i<n;i++)
#define for1(i,n)    for(int i=1;i<=n;i++)
#define forab(i,a,b) for(int i=a;i<=b;i++)
#define lcm(a, b)    ((a)*((b)/gcd(a,b)))
#define sq(a)		 (a)*(a)
#define endl		     "\n"
#define abs(x)		 fabs(x)
#define all(v) 		 v.begin(),v.end()
#define pcase(z,x)   cout<<"Case "<<z<<": "<<x<<"\n"
#define mod 1000000007
#define WakandaForever     ios_base::sync_with_stdio(0); cin.tie(0);

int main()
{
    WakandaForever
    int n;
    cin>>n;
    vi p,m;
    for0(i,n){
        int x,y;
        cin>>x>>y;
        p.pb(x+y);
        m.pb(x-y);
    }
    sort(all(p));
    sort(all(m));

    int a = p[0] - p.back();
    int b = m[0] - m.back();
    int c = - m[0] + m.back();
    int d = - p[0] + p.back();
    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    int ans = max({a,b,c,d});
    cout<<ans<<endl;

    return 0;
}