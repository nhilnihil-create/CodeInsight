#include<bits/stdc++.h>
#include<limits>
#define ll long long
#define F first
#define S second
#define pb push_back
#define oo 1e18
#define endl '\n'
#define si size()
#define all(v) v.begin(),v.end()
#define FASTIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define Matrix vector< vector < long long > >
#define vi vector<int>
#define vll vector<ll>
#define vd vector<double>
#define vs vector<string>

using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

const long double Pi=acos(-1),e=2.718;
const int N=3e3+10,mod=998244353;

int main ()
{
    FASTIO;
    ll n;
    cin >> n;
    vll a(n+1),Pre(n+1);
    for(auto &x:a)cin >> x;
    if(n==0){
        cout << (a[0]==1 ? 1 : -1) << endl;
        return 0;
    }
    if(a[0]!=0)return cout << -1 << endl,0;
    Pre[n] = a[n];
    for(int i=n-1;i>=0;i--){
        Pre[i] = Pre[i+1]+a[i];
    }
    ll ans=1,last=1;
    for(int i=1;i<=n;i++){
        if(a[i] > last*2)return cout << -1 << endl,0;
        ans += min(last*2,Pre[i]);
        last = min(last*2,Pre[i])-a[i];
    }
    cout << ans << endl;
    return 0;
}
/**


*/
