#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
ll MOD = 1000000007;
//ll INF = 21474836470000000;
ll INF = 1001001001001001001;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

ll ceil(ll a,ll b){
   return (a+b-1)/b;
}

ll K,Q;
ll D[5010];

int main(){
   cin >> K >> Q;
   rep(i,K) cin >> D[i];
   rep(i,Q){
      ll n,x,m;
      cin >> n >> x >> m;
      ll sum = x,eq = 0;
      rep(j,K){
         ll num = ceil(n - 1 - j,K);
         sum += (D[j] % m) * num;
         if(D[j] % m == 0) eq += num;
      }
      cout << (n - 1) - (sum / m - x / m) - eq << endl;
   }
}
