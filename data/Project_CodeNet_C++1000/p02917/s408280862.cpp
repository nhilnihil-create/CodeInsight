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

    int n;
    cin>>n;
    vi arr(n,0);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(i==1){
            arr[0]=arr[1];
        }
    }
    // sz of array=n+1;
    int sum=arr[n-1];
    for(int i=0;i<n-1;i++){
        arr[i]=min(arr[i],arr[i+1]);
        sum+=arr[i];
    }
    // for(int x:arr){cout<<x<<" ";}cout<<endl;
    cout<<sum<<endl;
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