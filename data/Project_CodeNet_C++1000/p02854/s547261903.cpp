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
    ll n;
    cin>>n;
    
    vector<vll> grid(2,vll (n,0));
    for(ll j=0;j<n;j++){
        cin>>grid[0][j];
        grid[1][j]=grid[0][j];
    }
    for(ll i=1;i<n;i++){
        grid[0][i]+=grid[0][i-1];
    }
    
    for(ll i=n-1-1;i>=0;i--){
        grid[1][i]+=grid[1][i+1];
    }
    
    ll ans=INT_MAX;
    for(int i=0;i<n-1;i++){
        ans=min(ans,abs(grid[0][i]-grid[1][i+1]));
    }
    cout<<ans<<endl;
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