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
 
const int maxx=100009;
 
// Happy Coding!


ll _distance(vll &arr,ll hom){
    ll sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=(hom-arr[i])*(hom-arr[i]);
    }
    return sum;
}
void solve(){
    ll n;
    cin>>n;
    
    ll l=101,r=-1;
    vector<ll> arr(n,0);
    if(n==0){cout<<"0";return ;}
    
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        l=min(l,arr[i]);
        r=max(r,arr[i]);
        
    }
    // cout<<l<<" "<<r<<endl;
    ll ans=INT_MAX;
    for(ll k=l;k<=r;k++){
        ll d=_distance(arr,k);
        ans=min(ans,d);
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