#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<int, int> Pi;
typedef vector<ll> Vec;
typedef vector<int> Vi;
typedef vector<string> Vs;
typedef vector<vector<ll>> VV;

#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
const ll INF=1e9;
const ll MAX=100005;
const ll MOD=1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a,b)
#define Each(a,b) for(auto &a :b)
#define REPM(i, mp) for (auto i = mp.begin(); i != mp.end(); ++i)
#define dbg(x_) cerr << #x_ << ":" << x_ << endl;
#define dbgmap(mp) cerr << #mp << ":"<<endl; for (auto i = mp.begin(); i != mp.end(); ++i) { cerr << i->first <<":"<<i->second << endl;}
#define dbgarr(n,m,arr) rep(i,n){rep(j,m){cerr<<arr[i][j]<<" ";}cerr<<endl;}
#define dbgdp(n,arr) rep(i,n){cerr<<arr[i]<<" ";}cerr<<endl;
#define sum(v) accumulate(ALL(v),0)
#define fi first
#define se second

template<typename T1, typename T2>
ostream &operator<<(ostream &s, const pair<T1, T2> &p) { return s<<"("<<p.first<<", "<<p.second<<")"; }

// vector
template<typename T>
ostream &operator<<(ostream &s, const vector<T> &v) {
    int len=v.size();
    for(int i=0; i<len; ++i) {
        s<<v[i];
        if(i<len-1) s<<"	";
    }
    return s;
}

// 2 dimentional vector
template<typename T>
ostream &operator<<(ostream &s, const vector<vector<T> > &vv) {
    int len=vv.size();
    for(int i=0; i<len; ++i) {
        s<<vv[i]<<endl;
    }
    return s;
}

int main() {
    cin.tie(0);
    cout<<std::setprecision(10);
    ios::sync_with_stdio(false);
    ll n,ans=0;
    cin>>n;
    Vec p(n);
    Vec ind(n);
    rep(i,n){
        int tmp;
        cin>>tmp;
        tmp--;
        p[i]=tmp;
        ind[tmp]=i;
    }
    multiset<int> st;
    st.insert(-1);
    st.insert(-1);
    st.insert(n);
    st.insert(n);
    per(i,n-1){
        int id = ind[i];
        st.insert(id);
        Vi l(2,-1);
        Vi r(2,n);
        auto it = st.find(id);
        --it;
        l[0]=*it;
        --it;
        l[1]=*it;
        it = st.find(id);
        it++;
        r[0] = *it;
        it++;
        r[1] = *it;
        int l1 = id-l[0];
        int r1 = r[0]-id;
        int l2 = l[0]-l[1];
        int r2 = r[1]-r[0];
        ans += (i+1) * (l1*r2 + l2*r1);
    }
    cout<<ans<<endl;
    return  0;
}
