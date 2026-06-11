#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> vec(n);
    for(ll i=0; i<n ;++i){
        cin>>vec[i];
    }
    sort(vec.begin(), vec.end());
    ll sum=0;
    for(ll i=0; i<k; ++i){
        sum += vec[i];
    }
    cout<<sum<<endl;

}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int q;
    q=1;
    // cin>>q;
    while(q--) solve();


    return 0;
}