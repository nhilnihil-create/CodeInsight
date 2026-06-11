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

ll _find(int d,int n){
    return n<100 ? pow(100,d)*n : 101*pow(100,d);
}

void solve(){
    
    
    ll n;
    cin>>n;
    
    vll M(n+1);
    for(ll i=0;i<=n;i++){
        cin>>M[i];
    }
    
    vll H(n);
    for(ll i=0;i<n;i++){
        cin>>H[i];
    }
    
    ll ans=0;
    for(ll i=0;i<n;i++){
        if(H[i]<=M[i]){
            ans+=H[i];
            M[i]-=H[i];
            H[i]=0;
        }
        else{
            ans+=M[i];
            H[i]-=M[i];
            M[i]=0;
            if(H[i]<=M[i+1]){
                ans+=H[i];
                M[i+1]-=H[i];
                H[i]=0;
            }
            else{
                ans+=M[i+1];
                H[i]-=M[i+1];
                M[i+1]=0;
            }
        }
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