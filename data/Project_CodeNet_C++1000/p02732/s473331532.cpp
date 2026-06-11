#include<bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

#pragma GCC optimize("Ofast")



using namespace std;

bool is_integer( float x ){
    return floor(x) == x;
}
bool is_integer(double x){
    return floor(x) == x;
}


int main() {

    int n; cin >> n;
    vector<ll> a(n);
    vector<ll> c(n);
    vector<ll> b(200001);
    vector<pair<ll,ll>> m;
    int p = 0;
    ll ans = 0;

    rep(i,n){
        cin >> a[i];
        c[i] = a[i];
    }
    sort(a.begin(),a.end());

    rep(i,n){
        if(m.empty()) m.push_back(make_pair(a[i],1));
        else if(a[i] == m[p].first) m[p].second ++;
        else{
            m.push_back(make_pair(a[i],1));
            p ++;
        }
    }

    rep(i,m.size()){
        b[m[i].first] = m[i].second;
        ans += ((m[i].second)*(m[i].second-1))/2;
    }

    rep(i,n){
        cout << ans - (b[c[i]]-1) << endl;
    }




    return 0;
}









