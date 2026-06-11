#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define  all(v)     (v).begin(),(v).end()
#define  rall(v)    (v).rbegin(),(v).rend()
#define  pb         push_back
#define  eb         emplace_back
#define  mp         make_pair
#define  ff         first
#define  ss         second
#define  pf         push_front
#define  bs         binary_search
#define  lb         lower_bound
#define  ub         upper_bound
#define  dec(x)   fixed<<setprecision(x)
#define  lcm(a,b)   (a*b/__gcd(a,b))
const ll inf=LLONG_MAX;
const ll mod=1e9+7;
const ld pi=acos(-1);
                    
void solution(){
    ll n,x,t;
    cin>>n>>x>>t;
    ll ans=ceil(n*1.0/x*1.0);
    cout<<ans*t;
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    t=1;
   // cin>>t;
    while(t--){
        solution();
        cout<<"\n";
    }
    return 0;
}
