#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int N = 2e5+5;
const ll mod = 1e9+7;
ll b[N];
ll a[N];
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>b[i];
    ll sum = 0;
    for(int i=0;i<n;i++){
        sum+=b[i];
    }
    for(int i=0;i<n-1;i+=2){
        sum-=b[i];
        sum-=b[i];
    }
    a[n-1] = sum;
    for(int i=n-2;i>=0;i--){
        a[i] = 2*b[i]-a[i+1];
    }
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
  //  cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/// 3 8 7 5 5
/// a0/2 + a1/2
/// a1/2 + a2/2
/// a2/2 + a3/2
/// a3/2 + a4/2
/// a4/2 + a0/2


