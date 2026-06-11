#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;



int main(){
    ll n,k,s;
    cin >> n >> k >> s;
    vector<ll> res;
    for(ll i=0;i<k;i++){
        res.push_back(s);
    }
    if(s!=1e9){
        for(ll i=0;i<n-k;i++){
            res.push_back(1e9);
        }
    }
    else{
        for(ll i=0;i<n-k;i++){
            res.push_back(1e9-1);
        }
    }
    for(ll i=0;i<n;i++){
        cout << res[i];
        if(i!=n-1) cout << " ";
    }
    cout << endl;
    return 0;
}  
