#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll k;cin>>k;
    ll n = (1ll<<k);
    multiset<ll> st;
    for(ll i=0;i<n;i++){
        ll x;cin>>x;
        st.insert(x*-1);
    }
    vector<ll> a;
    a.push_back(*st.begin());
    st.erase(st.begin());
    for(ll i=0;i<k;i++){
        vector<ll> tmp;
        for(auto &ele:a){
            if(st.upper_bound(ele)==st.end())return cout<<"No" , 0;
            tmp.push_back(*(st.upper_bound(ele)));
            st.erase(st.upper_bound(ele));
        }
        for(auto &ele:tmp)a.push_back(ele);
        sort(a.begin(),a.end());
    }
    cout<<"Yes";
}