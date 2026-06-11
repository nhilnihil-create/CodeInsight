#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<pll> p(n);
    rep(i,n){
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p.begin(),p.end(),greater<pll>());
    ll ans = 0;
    set<ll> st;
    st.insert(-1);
    st.insert(n);
    st.insert(p[0].second);
    for(int i=1;i<n;i++){
        
        auto it1 = st.lower_bound(p[i].second);
        auto it2 = it1;
        --it2;
        
        if(it2 != st.begin()){
            auto it3 = it2;
            --it3;
            ans += p[i].first * ((*it1) - (p[i].second)) * ((*it2) - (*it3)); 
        }
        ++it1;
        if(it1 != st.end()){
            auto it4 = it1;
            --it4;
            ans += p[i].first * ((*it1) - (*it4)) * ((p[i].second) - (*it2));
        }
        
        st.insert(p[i].second);
    }
    cout << ans << endl;
    return 0;
}