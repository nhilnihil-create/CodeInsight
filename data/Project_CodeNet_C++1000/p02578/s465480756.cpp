#include<bits/stdc++.h>

using namespace std;
#define ll  long long
#define ld  long double
#define endl '\n'
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll MOD = (ll) 1e9 + 7;
const double PI = 3.141592653589793238463;
const int MAXN = 1000005;

int main() {
    FAST
    int n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    ll mx=arr[0];
    ll ans=0;
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1])
        {
            ans+=abs(arr[i]-mx);
            arr[i]=mx;
        }
        mx=max(mx,arr[i]);
    }
    cout<<ans<<endl;

    return 0;
}
