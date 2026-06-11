#include "bits/stdc++.h"
using namespace std;
using ll = long long;

template <typename T>
void print_vec(const vector<T>& v, bool is_reverse=false, ll num=0){
  if(num == 0) num = (ll)v.size();
  cout << endl; cout << "i=  ";for(ll i=0; i<num; i++) cout << i << "   ";cout << endl;  
  cout << "    ";
  if(is_reverse) for(ll i=num-1; i>=0; i--){ cout<<v[i]; if(i!=0) cout<<"   ";}
  else for(ll i=0; i<num; i++){ cout<<v[i]; if(i!=num-1) cout<<"   ";}
  cout << endl;
}

// template <typename T>
// void print_pairvec(const vector<T> &v, ll num=0){
//   if(num == 0) num = (ll)v.size();
//   cout << endl; for(ll i=0; i<num; i++){ cout << v[i].first << " " << v[i].second << endl;}
// }
template <typename T>
void print_pairvec(const T &_pair, ll num=0){
  cout << endl; for(pair<ll, int> x: _pair){ cout << x.first << " " << x.second << endl;}
}

template <typename T>
void print_vec2(const vector<vector<T>>& v){
  cout << endl; cout << "       ";
  for(ll i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(ll i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(ll j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}

struct Eratosthenes{
  vector<ll> sieve;// sieve[i]: 数字iがエラトステネスで篩落とされた時の素数

  Eratosthenes(ll n): sieve(n+1){
    for(int i=0; i<=n; i++) sieve[i] = i;
    for(ll i=2; i*i<=n; i++){
      if(sieve[i] < i) continue;
      for(ll j=i*i; j<=n; j+=i) sieve[j] = min(sieve[j], i);
    } 
  }

  vector<ll> prime_divisors(ll x, bool tmp=false){
    vector<ll> res(1,1);//back()のところで ひっかかるので1を入れとかないとダメ
    while(x > 1){
      if(res.back() != sieve[x]) res.push_back(sieve[x]);
      x /= sieve[x];
    }
    return res;
  }

  map<ll, int> prime_divisors(ll x, int tmp=0){
    map<ll, int> mp;
    while(x > 1){
      mp[sieve[x]]++;
      x /= sieve[x];
    }
    return mp;
  }
};

int main(){
  int N;
  cin >> N;
  
  // 解2 調和級数
  const int INF = 1e7+1;
  vector<int> vec(INF, 0);
  for(int i=1; i<=INF; i++){
    for(int j=1; j*i<=INF; j++) vec[i*j]++;
  }
  // cout << " vec: "; print_vec(vec, false, 5);
  ll ans = 0;
  for(int k=0; k<=N; k++) ans += (ll)k * vec[k];
  cout << ans << endl;
  return 0;
  
  // 解1 高速な素因数分解 (cf. ABC177 E)
  // const int INF = 1e7;
  // Eratosthenes era(INF);
  // ll ans = 0;
  // for(int k=1; k<=N; k++){
  //   map<ll, int> mp = era.prime_divisors(k, 0);
  //   int num = 1;//約数の個数を数える
  //   for(pair<ll, int> x : mp) num *= x.second+1;
  //   ans += (ll)k * num;
  // }
  // cout << ans << endl;
  // return 0;
}
