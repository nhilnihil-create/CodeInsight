#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ll          long long
#define pb          push_back
#define INF         9223372036854775807
#define    endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define lower(u)    transform(u.begin(), u.end(), u.begin(), ::tolower);//convert string u to lowercase;
#define upper(u)    transform(u.begin(), u.end(), u.begin(), ::toupper);
using namespace std;

using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define N  100005

void solve()
{
    double a,b,h,m;
    cin>>a>>b>>h>>m;
    double pi=2;
    pi=pi*acos(-1.0);
    
    // pi=pi*2.0;
    // cout<<pi<<endl;
    h=h/((double)12.0);
    m=m/((double)60.0);
    h+=m/12;
    double theta=(h-m)*pi;
    // cout<<theta<<endl;
    double c=a*a+b*b-2.0*a*b*cos(theta);
    c=sqrt(c);
    cout<<setprecision(12)<<c<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int TESTS=1;
//    cin>>TESTS;
    while(TESTS--)
    {
        solve();
    }
    return 0;
}