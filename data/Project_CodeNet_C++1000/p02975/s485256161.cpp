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
const string YES = "Yes";
const string NO = "No";
void solve(long long N, std::vector<long long> a){
  if(N%3 == 0){
    ll n = 0;
    sort(all(a));
    for (int i = 0; i < 3; i++) {
      bool can = true;
      for (int l = 0; l < N/3; l++) {
        n ^= a[l+i*(N/3)];
        if(l != 0){
          if(a[l + i*(N/3)] != a[l + i*(N/3) - 1])can = false;
        }
      }
      if(!can){
        cout << NO << endl;
        return;
      }
    }
    cout << (n == 0 ? YES : NO) << endl;
    return;
  }else{ //Nが3の倍数では無いとき
    bool all_zero = true;
    for (int i = 0; i < N; i++) {
      if(a[i] != 0)all_zero = false;
    }
    cout << (all_zero ? YES : NO) << endl;
    return;
  }
}

int main(){
    long long N;
	scanf("%lld",&N);
	std::vector<long long> a(N);
	for(int i = 0 ; i < N ; i++){
		scanf("%lld",&a[i]);
	}
    solve(N, std::move(a));
}
