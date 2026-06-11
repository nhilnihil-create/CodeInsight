#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    vector<pair<ll,ll>> vec;
    for(ll i=0;i<n;i++){
        ll a,b;
        cin >> a >> b;
        vec.push_back(make_pair(b,a));
    }
    sort(vec.begin(),vec.end());
    ll count=0;
    bool ok=true;
    for(auto v:vec){
        count+=v.second;
        if(count>v.first){
            ok=false;
            break;
        }
    }
    cout << (ok?"Yes":"No") << endl;
    return 0;
}
