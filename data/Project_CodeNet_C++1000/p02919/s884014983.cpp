#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF=1e18;

int main(){
  	cin.tie(0);ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    V<ll> a(n);
    set<ll> st;
    map<ll,ll> mp;
    rep(i,n){
        cin>>a[i];
        st.insert(i+1);
        mp[a[i]]=i+1;
    }
    st.insert(-1);
    st.insert(0);
    st.insert(n+1);
    st.insert(n+2);
    ll ans=0;
    for(ll i=1;i<n;i++){
        ll s,t,u,v;
        auto it1=st.find(mp[i]);
        auto it2=st.find(mp[i]);
        auto it3=st.find(mp[i]);
        auto it4=st.find(mp[i]);
        auto it=st.find(mp[i]);
        it1--;
        it1--;
        it2--;
        it3++;
        it4++;
        it4++;
        if(*it1==-1) s=0;
        else s=*it1;
        t=*it2;
        u=*it3;
        if(*it4==n+2) v=n+1;
        else v=*it4;
        ans+=((t-s)*(u-*it)+(*it-t)*(v-u))*i;
        it=st.erase(it);
    }
    cout<<ans<<endl;
}
