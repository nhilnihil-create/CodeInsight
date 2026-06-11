#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
int main(){
    ll n;cin>>n;
    vector<ll>p(n);
    rep(i,n){
        ll a;cin>>a;p[n-a]=i;
    }
    set<ll>st;
    st.insert(p[0]);
    st.insert(n);
    st.insert(-1);
    ll ans=0;
    set<ll>st2;
    st2.insert(n-p[0]-1);
    st2.insert(n);
    st2.insert(-1);
    REP(i,1,n){
        if(*st.upper_bound(p[i])!=n){
            auto itr=st.upper_bound(p[i]);
            auto itr2=st.upper_bound(*itr);
            auto itr3=st2.upper_bound(n-1-p[i]);
            ans+=(*itr2-*itr)*(*itr3-(n-p[i]-1))*(n-i);
            //cout<<*itr<<' '<<*itr2<<' '<<n-1-*itr3<<endl;
        }
        if(*st2.upper_bound(n-1-p[i])!=n){
            auto itr=st2.upper_bound(n-1-p[i]);
            auto itr2=st2.upper_bound(*itr);
            auto itr3=st.upper_bound(p[i]);
            ans+=(*itr2-*itr)*(*itr3-p[i])*(n-i);
        }
        st.insert(p[i]);
        st2.insert(n-p[i]-1);
    }
    cout<<ans<<endl;
}