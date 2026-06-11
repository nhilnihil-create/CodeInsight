#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LLMAX (1ll << 60) - 1
#define INTMAX (1 << 30) - 1
#define MOD 1000000007 
#define NMAX 1000*100+1

#define numberOfSetBits(S) __builtin_popcount(S) // __builtin_popcountl(S) __builtin_popcountll(S)
#define MSET(x,y) memset(x,y,sizeof(x))
#define gcd(a,b) __gcd(a,b)
#define all(x)  x.begin(),x.end()
#define isOn(S, j) (S & (1 << j))
#define endl '\n'
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define print(x)    for(auto it:x) cout<<it<<' '; cout<<endl;
#define printii(x)  for(auto it:x) cout<<it.F<<' '<<it.S<<'\t';  cout<<endl;
#define in(x,n)   for(int e=0;e<n;e++){ll y;cin>>y;x.pb(y);}

#define vi vector<ll>
#define vvi vector<vi>
#define ii pair<ll,ll>
#define pll pair<ll,ll>
#define vii vector<ii>
#define vvii vector<vii>
#define viii vector<pair<ii,ll>>
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define mc(a,b,c) mp(mp(a,b),c)
map<ii,ll> ma;
vvi adj;
vi col,dep;

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cout << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

ll dfs(ll v){
    if(dep[v]!=-1)return dep[v];
    col[v] = 1;
    ll res = 0;
    for(auto it: adj[v]){
        if(col[it]==1){
            return dep[v] = 1e18;
        }
        else{
            res=max(res,dfs(it));
        }
    }
    col[v] = 2;
    return dep[v] = res+1;
}

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x,t,m,y,z;
    cin>>n;
    ll cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ma[mp(i,j)] = cnt++;
        }
    }
    adj.resize(cnt);
    col.assign(cnt,0);
    dep.assign(cnt,-1);
    
    for(int i=0;i<n;i++){
        y = -1;
        for(int j=0;j<n-1;j++){
            cin>>x;
            x--;
            ll u=i,v=x;
            if(u>v)swap(u,v);
            x = ma[mp(u,v)];
            if(y!=-1){
                adj[y].pb(x);
            }
            y = x;
        }
    }
    ll res = 0;
    for(int i=0;i<cnt;i++){
        if(col[i]==0){
            res = max(res,dfs(i));
        }
    }
    cout<<(res>=1e18?-1:res);
    

            
    


    return 0;
}