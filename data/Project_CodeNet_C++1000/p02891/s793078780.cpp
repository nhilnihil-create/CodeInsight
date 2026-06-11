#include <bits/stdc++.h>
// Hey! 僕の提出を見てくれてありがとう.
// ロボ子さん可愛いぞ！！！！！君もV沼にはまろう↓
// https://www.youtube.com/channel/UCDqI2jOz0weumE8s7paEk6g
using namespace std;
using ll = long long;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}//a,bの最大公約数(gcd)を求める
ll lcm(ll a,ll b){return abs(a*b)/gcd(a,b);}//a,bの最小公倍数(lcm)を求める
vector<ll> enum_div(ll n){vector<ll> ret;for(int i=1 ; i*i<=n ; i++){if(n%i == 0){ret.push_back(i);if(i!=1 && i*i!=n)ret.push_back(n/i);}}ret.push_back(n);return ret;}
//↑nの約数を求める
vector<bool> IsPrime; void sieve(size_t max){if(max+1 > IsPrime.size())IsPrime.resize(max+1,true);IsPrime[0] = false;IsPrime[1] = false;for(size_t i=2; i*i<=max; ++i)if(IsPrime[i])for(size_t j=2; i*j<=max; ++j)IsPrime[i*j] = false;}
//↑エラトステネスの篩で素数を求める
#define roundup(divisor,dividend) (divisor + (dividend - 1)) / dividend //切り上げ割り算
#define all(x) (x).begin(),(x).end() //xの初めから終わりまでのポインタ
#define size_t ll //size_tは自動でllに変換される
#define pb(x) push_back(x)
#define pri_queue priority_queue //優先度付きキュー
#define syo(x) fixed << setprecision(x) //iostreamで小数をx桁表示
//sortを降順にする時は greater<型>()

void solve(std::string S, long long K){
  bool can = true;
  ll ans=0; string x = S;
  ll n=0;
  for (int i = 0; i < S.length()-1; i++) {
    if(S[i] == S[i+1]){
      n++;
    }else{
      n++;
      can = false;
      ans += n/2;
      n=0;
    }
  }
  n++;
  ans += n/2;
  if(!can){
    S = x;
    ll i=0,a=0,b=0;
    if(S[0] == S[S.length()-1]){
      while(S[0] == S[i]){
        a++;i++;
      }
      i=S.length()-1;
      while(S[S.length()-1] == S[i]){
        b++;i--;
      }
    }
    cout << ans*K - (a/2 + b/2 -(a+b)/2)*(K-1) << endl;
  }else{
    cout << S.length()*K/2  << endl;
  }
}

int main(){
    std::string S;
				std::cin >> S;
				long long K;
				scanf("%lld",&K);
    solve(S, K);
    return 0;
}
