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
const ll INF=1e16+18;
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
    ios::sync_with_stdio(false);
    cout<<std::setprecision(10);

    ll n;
    cin>>n;
    Vec a(n);
    rep(i,n)cin>>a[i];

    Vec p;
    Vec m;
    rep(i,n){
        if(a[i]>=0){
            p.pb(a[i]);
        }else{
            m.pb(a[i]);
        }
    }
    ll q = n-1;

    if(m.size()==0){
        sort(ALL(p));
        m.pb(p[0]);
        p.erase(p.begin());
    }

    if(p.size()==0){
        sort(ALL(m));
        reverse(ALL(m));
        p.pb(m[0]);
        m.erase(m.begin());
    }

    ll mi = m.size()-1;
    ll pi = p.size()-1;

    vector<P> pr;
    bool change = false;
    ll tmp = p[pi];
    pi--;

    while(q--){
        if(mi==0&&pi>-1){
            pr.emplace_back(m[0],tmp);
            tmp = m[mi]-tmp;
            mi--;
            change = true;
            continue;
        }
        if(!change){
            pr.emplace_back(tmp,m[mi]);
            tmp = tmp-m[mi];
            mi--;
        }else{
            if(pi==0){
                pr.emplace_back(p[0],tmp);
                tmp = p[0]-tmp;
                break;
            } else{
                pr.emplace_back(tmp,p[pi]);
                tmp = tmp-p[pi];
                pi--;
            }
        }
    }
    cout << tmp << endl;
    rep(i,n-1){
        cout<<pr[i].fi<<" "<<pr[i].se<<endl;
    }

    return  0;
}
