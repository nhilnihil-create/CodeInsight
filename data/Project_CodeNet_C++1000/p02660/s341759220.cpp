#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double lld;
ll MOD = (1e9)+7;
const int dr[] = {+1, -1, +0, +0, +1, -1, +1, -1};
const int dc[] = {+0, +0, +1, -1, +1, -1, -1, +1};
const int kx[] = {+1, +2, -1, -2, +1, +2, -1, -2};
const int ky[] = {+2, +1, +2, +1, -2, -1, -2, -1};
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
inline void fastIO(){
  ios_base::sync_with_stdio(0);cin.tie(0);
}
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void debug_out() { cerr << endl; }
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << ' ' << H; debug_out(T...); }

#ifdef LOCAL
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", debug_out(__VA_ARGS__)
#else
#define debug(...) 47
#endif
bool isPrime(ll x){
  if(x==1)return false;
  for(ll i=2;i*i<=x;i++){
    if(x%i==0){
      return false;
    }
  }
  return true;
}
int main(){
  fastIO();
  ll n,ans=0,c=10;
  cin>>n;
  set<ll>factors;
  vector<ll>prime_factors;
  map<ll,ll>reps;
  map<ll,ll>seen_primes;
  factors.insert(n);
  for(int i=2;i<=sqrt(n)+c;i++){
    if(n%i==0){
      factors.insert(i);
      if(n%(n/i)==0){
        factors.insert(n/i);
      }
    }
  }
  for(set<ll>::iterator it=factors.begin();it!=factors.end();it++){
    ll value=*it;
    if(isPrime(value)){
      while(n%value==0){
        prime_factors.push_back(value);
        n/=value;
      }
    }
  }
  for(int i=0;i<prime_factors.size();i++){
    reps[prime_factors[i]]++;
  }
  for(int i=0;i<prime_factors.size();i++){
    ll take=1;
    if(seen_primes[prime_factors[i]]>0)continue;
    while(reps[prime_factors[i]]-take>=0){
      reps[prime_factors[i]]-=take,take++,ans++;
    }
    seen_primes[prime_factors[i]]++;
  }
  cout<<ans<<endl;
  return 0;
}
