#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
 
typedef vector<int> vi;;
typedef vector<ll> vll;

#define l() length()
#define sz() size()
 
#define b() begin()0
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



void solve(){
    int n;
    cin>>n;
    vi arr(n);
    for(int i=0;i<n;i++){cin>>arr[i];}
    
    sort(all(arr));
    int idx=n/2 - 1;
    cout<<arr[idx+1]-arr[idx];
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