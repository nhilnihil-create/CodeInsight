#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
//const ll MOD=998244353;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll gcd(ll a,ll b){
   if(a%b==0){
       return(b);
   }
   else{
       return(gcd(b,a%b));
   }
}

ll lcm(ll a,ll b){
   return a/gcd(a,b)*b;
}

//https://qiita.com/drken/items/a14e9af0ca2d857dad23

//N=1の時に自分で対応しなきゃいけないから注意
vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main()
{
  ll A,B; cin>>A>>B;
  ll G=gcd(A,B); if(G==1) {cout<<1<<endl; return 0;}
  vector<pair<ll,ll>> vec=prime_factorize(G);
  cout<<vec.size()+1<<endl;
  return 0;
}
