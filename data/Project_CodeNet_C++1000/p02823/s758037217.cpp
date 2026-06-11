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

bool _find(vi &arr,int n){
    
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]){
            arr[i]--;
        }
        else if(arr[i]<arr[i-1]){
            return false;
        }
    }
    return true;
}
int sameParity(int a,int b){
    if(a%2==0 && b%2==0){return 1;}
    if(a%2!=0 && b%2!=0){return 1;}
    return 0;
}
void solve(){
    
    ll n,a,b;
    cin>>n>>a>>b;
    
    // if 1 of them is odd and the other one even, they won't ever meet
    // unless ....!
    ll ans=(b-a)/2;
    if(!sameParity(a,b)){
        ans+=1+min(a-1,n-b);
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