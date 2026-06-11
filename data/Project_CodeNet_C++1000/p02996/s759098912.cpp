#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

template<class T> inline bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}


int main(){

    int n;
    cin >> n;
    vector<pair<ll, ll>> work(n);
    for(int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        work[i] = make_pair(b, a);
    }
    sort(work.begin(), work.end());
    ll sum = 0;
    bool ok = true;
    for(int i = 0; i < n; i++){
        sum += work[i].second;
        if(sum > work[i].first) ok = false;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}