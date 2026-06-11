#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=998244353;
signed main(){
    ll n;cin>>n;
    multiset<ll>st;
    rep(i,1<<n){
        ll a;cin>>a;
        st.insert(-a);
    }
    ll s=*st.upper_bound(-inf);
    st.erase(st.find(s));
    vector<ll>a(0);
    a.pb(s);
    bool f=1;
    rep(i,n){
        vector<ll>b(0);
        rep(j,a.size()){
            auto itr=st.upper_bound(a[j]);
            if(itr==st.end())f=0;
            else{
                b.pb(*itr);
                st.erase(itr);
            }
        }
        rep(j,b.size()){
            a.pb(b[j]);
        }
        sort(all(a));
        /* cout<<i<<' ';
        rep(j,a.size())cout<<a[j]<<' ';
        cout<<endl;*/
    }
    if(f)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}