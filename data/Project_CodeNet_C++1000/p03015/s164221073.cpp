#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
#define getbit(n, i) (((n) & (1LL << (i))) != 0) 
#define setbit0(n, i) ((n) & (~(1LL << (i)))) 
#define setbit1(n, i) ((n) | (1LL << (i))) 
#define togglebit(n, i) ((n) ^ (1LL << (i))) 
#define lastone(n) ((n) & (-(n))) 
char gap = 32;
template<typename T> 
ostream& operator<<(ostream &os, const vector<T> &v) { 
    os << '{'; 
    for (const auto &x : v) os << gap << x;
        return os << '}'; 
}
template<typename A, typename B> 
ostream& operator<<(ostream &os, const pair<A, B> &p) {
        return os << '(' << p.first << gap << p.second << ')';
}

template <class T>
void read(T &x) {
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        ;
    for (x = 0; c <= '9' && c >= '0'; c = getchar()) x = x * 10 + (c & 15);
}
#define ll int 
#define lll __int128_t
#define pb push_back
#define mp make_pair
typedef pair < int,int> ii;
typedef vector<ii> vii;
typedef vector<ll>vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll hashPrime = 1610612741;
string s;
ll sz;
ll dp[1000005][2];
#define mod 1000000007
ll recurse(ll pos,ll tight){
  ll ans=0;
  if(pos==sz)return 1;
  if(dp[pos][tight]!=-1)return dp[pos][tight];
  if(tight==1){
    if(s[pos]=='1'){
      ans=recurse(pos+1,0)%mod;
      ans=(ans+(2*recurse(pos+1,tight))%mod)%mod;
    }
    else{
      ans=recurse(pos+1,1)%mod;
    }
  }
  else{
      ans=recurse(pos+1,0)%mod;
      ans=(ans+(2*recurse(pos+1,0))%mod)%mod;
  }
  return dp[pos][tight]=ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>s;
    sz=s.size();
    cout<<recurse(0,1);
}