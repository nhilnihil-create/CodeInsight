#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first > b.first;
    }
}

const ll tmax = 1000000000;

int main(){
    int n; cin >> n;
    vector<pair<ll, ll>> p;
    for(int i=0; i<n; ++i){
        ll a, b; cin >> a >> b;
        p.push_back({a, b});
    }
    sort(p.begin(), p.end(), compare); 
    
    ll now = 0; bool ok = true;
    for(auto it=p.begin(); it!=p.end(); ++it){
        now += (it->first); 
        if(now>(it->second)){ok = false; break;}
    } 
    if(ok){cout << "Yes" << endl;}
    else{cout << "No" << endl;}
    return 0;
}