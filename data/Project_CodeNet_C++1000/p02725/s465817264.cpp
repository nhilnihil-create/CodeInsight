// Hail god Yato
 
#include <bits/stdc++.h> 
using namespace std;
 
#define hs ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll mod = 1000000007;
const ll INF = 1e18;
const ll MAX = 100001;
//
//
void solve(){
    int k, n;
    cin>>k>>n;
    vector<int> vec(n);
    for(int i = 0; i< n; i++)
        cin>>vec[i];
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        if(i == 0)
            ans = min(ans, vec[n-1]-vec[0]);
        else
            ans = min(ans, k-(vec[i]-vec[i-1]));
    }
    cout<<ans;
}
int main(){ 
        hs;
        ll t;
        t=1;
        // cin>>t;
        for (int i=1; i<=t; i++){
                //cout<<"Case #"<<i<<": ";
                solve();
         }
        return 0; 
}