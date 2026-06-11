#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
 
typedef vector<int> vi;;
typedef vector<ll> vll;

#define l() length()
#define sz() size()
 
#define b() begin()
#define e() end()
#define all(x) x.begin(), x.end()
 
#define pb(i) push_back(i)
#define PB() pop_back()
 
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define Fi first
#define Se second
 
const int maxx=1e6+9;
 
// Happy Coding!


void solve(){
    
    ll n,m,d;
    cin>>n>>m>>d;
    vll A(n),B(m);
    for(ll i=0;i<n;i++){cin>>A[i];}
    for(ll i=0;i<m;i++){cin>>B[i];}
    
    ll cost=*min_element(all(A)) + *min_element(all(B));
    for(ll i=0;i<d;i++){
        ll x,y;
        ll c;
        cin>>x>>y>>c;
        x--;y--;
        cost=min(cost,A[x]+B[y]-c);
    }
    cout<<cost<<endl;
    
}

int main() {
    faster;
    int t=1;
    // cin>>t;
    while(t-->0){
        solve();
    }
	return 0;
}