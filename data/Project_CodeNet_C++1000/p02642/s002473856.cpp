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
  vector<int> A(N);
  for(int i=0; i<N; i++) cin >> A[i];

  sort(A.begin(), A.end());//82行目のbreakを入れないとTLEになるらしく，それならsortしないといけない
  const int INF  =1e6+1;// sortじゃなくてこっちがTLEの原因?// 81行目を追加して1e6+1でやってみる
  // const int INF = A.back()+1;
  vector<int> vec(INF, 0);
  for(int i=0; i<N; i++){
    if(vec[A[i]] >= 2) continue;// 84行目の代わり
    for(int j=1; j*A[i]<=INF; j++){
      vec[A[i]*j]++;
      // if(vec[A[i]*j] >= 2) break;// これいれたらWA?
    }
  }
  int ans = 0;
  for(ll i=0; i<N; i++){
    if(vec[A[i]] == 1) ans++;
  }
  cout << ans << endl;
  return 0;
}
