#include <bits/stdc++.h>
#define rep(i, a, b) for(ll i = a; i < b; i++)
using namespace std;
typedef long long ll;

int main(){
    ll N; cin >> N;
    ll ans = 0;
    vector<int> P(N+1), rP(N+1);
    set<ll> st;
    rep(i, 1, N+1) cin >> P[i];
    rep(i, 1, N+1) rP[P[i]] = i;
    rep(i, 0, N + 2) st.insert(i);
    //vector<ll> R1(N+1,0), R2(N), L1(N,0), L2(N,0);

    rep(i, 1, N){
        st.erase(rP[i]);
        auto r1 = st.upper_bound(rP[i]);
        auto l1 = r1; l1--;
        cerr << *l1 << " " << *r1 << endl;
        if(*r1 != N + 1){
            auto r2 = r1;
            r2++;
            ans += i * (rP[i] - *l1) * (*r2 - *r1);
        }
        if(*l1 != 0){
            auto l2 = l1; l2--;
            ans += i * ((*l1 - *l2) * (*r1 - rP[i]));
        }
        cerr << ans << endl;
        
        //ans += i * ((rP[i] - *l1)*(*r2 - *r1) + (*l2 - *l1) * (*r1 - rP[i]));
        
        //st.erase(rP[i]);
    }
    
    cout << ans << endl;
    // vector<pair<int,int> > p(N);
    
    //sort(P.begin(), P.end());

    //for(auto )
    

    return 0;
}