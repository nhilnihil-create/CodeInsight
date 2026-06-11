#include <bits/stdc++.h>
using namespace std;
#define X ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FIXED_FLOAT(x) std::fixed <<std::setprecision(2)<<(x)


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


long long p = 1e9+7;
typedef pair<int, int> pi;
typedef unordered_map<int, int> UMP;
typedef long long ll;
typedef vector<ll> VI;
#define FOR(i,b) for(i=0;i<b;i++)
#define pb push_back


void printa(VI x,ll n){
    ll i;
    FOR(i, n){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}

int main(){

    ll r,s,p,n,k,i;
    string a;
    cin>>n>>k;
    cin>>r>>s>>p;
    cin>>a;
    map<char, int> co;
    co['r']=r; co['s']=s;co['p']=p;
    map <char, char> mp;
    mp['s'] = 'r';mp['r']='p';mp['p']='s';
    string x;
    FOR(i,n){x+="?";}
    ll ans =0 ;
    FOR(i, n){
        if(i>=k){
            if(mp[a[i]]==x[i-k]){continue;}
        }
        x[i] = mp[a[i]];
        ans += co[mp[a[i]]];
    }
    cout<<ans;

}

// 2017634310362021