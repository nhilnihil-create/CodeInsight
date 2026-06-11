#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef long double ld;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fbo find_by_order
#define ook order_of_key
#define INF (ll)1e18
#define PI (ld)3.14159265358979323846
#define print(a); for(auto x:a)cout<<x<<" "; cout<<"\n";
#define mset(a); memset(a,0,sizeof(a));

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
    ll a,b;cin>>a>>b;
    if((a+b)&1)cout<<"IMPOSSIBLE\n";
    else cout<<(a+b)/2<<"\n";
}
