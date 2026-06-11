#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> Vec;

#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define rep(i, n) REP(i, 0, n)
const int INF=1e9;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define ALL(v) v.begin(), v.end()
#define dbg(x_) cerr << #x_ << ":" << x_ << endl;
#define pb(x) push_back(x)
#define sum(v) accumulate(ALL(v),0)

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

ll ans[100005];
static const ll MOD = 1e9+7;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll lcount=0;
    ll ans=1;

    vector<string> v(n*2);
    rep(i,n*2){
        if(s[i]=='B'){
            if(i%2==0){
                v[i]='L';
            }else{
                v[i]='R';
            }
        }else{
            if(i%2==0){
                v[i]='R';
            }else{
                v[i]='L';
            }
        }
    }
    rep(i,v.size()){
        if(v[i]=="L"){
            lcount++;
        }else{
            ans *= lcount;
            ans %= MOD;
            lcount--;
        }
        if(lcount<0){
            cout << 0 << endl;
            return 0;
        }
    }
    vector<string> w = v;
    sort(ALL(w));
//    dbg(w);
//    dbg(w[n]);
//    dbg(w[n+1]);
    if(w[n-1]!="L"||w[n]!="R"){
        cout << 0 << endl;
        return 0;
    }
    ll m = n;
    while (m>0){
        ans *= m;
        ans %= MOD;
        m--;
    }
    cout << ans << endl;
    return  0;
}
