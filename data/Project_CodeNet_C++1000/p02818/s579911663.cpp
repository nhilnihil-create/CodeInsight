#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define se second
const int N = 2e5+5;
void solve(){
    ll a,b,k;
    cin>>a>>b>>k;
    ll d = min(a,k);
    cout<<a-d<<" "<<max(0ll,b-(k-d))<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
   // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
