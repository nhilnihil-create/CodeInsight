#include<bits/stdc++.h>
#include<limits>
#define ll long long
#define F first
#define S second
#define pb push_back
#define oo (1LL<<63-1)
#define endl '\n'
#define si size()
#define all(v) v.begin(),v.end()
#define FASTIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define Matrix vector< vector < long long > >


using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

const long double Pi=acos(-1),e=2.718;
const int N=2e5+10,mod=1e9+7;

ll __lcm(ll x,ll y){
    return x*y/__gcd(x,y);
}
int main ()
{
    FASTIO
    ll n , m;
    cin >> n >> m;
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin >> a[i];
    ll lcm=1;
    for(int i=0;i<n;i++){
        lcm = __lcm(lcm,a[i]/2);
    }
    for(int i=0;i<n;i++){
        if((2*lcm/a[i])%2==0)return cout << 0 << endl,0;
    }
    ll ans = ceil(1.0*(m-lcm+1)/(2*lcm));
    cout << ans << endl;


    return 0;
}
/**

*/
