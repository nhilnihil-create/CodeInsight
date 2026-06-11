#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

// 約数列挙 O(√n)
vector<ll> divisor(ll n){
  vector<ll> res;
  for(ll i = 1; i * i <= n; i++){
    if(n % i == 0){
      res.push_back(i);
      if(i != n / i) res.push_back(n / i);
    }
  }
  return res;
}

bool solve(vector<ll> v, ll K, ll r){

  ll sum = 0;
  for(int i = 0; i < v.size(); i++){
    v[i] %= r;
    sum += v[i];
  }
  if(sum == 0) return true;

  sort(v.begin(), v.end());
  vector<ll> w(v.size());

  w[0] = v[0];
  for(int i = 1; i < w.size(); i++){
    w[i] = w[i-1] + v[i];
  }
  // cerr << w[w.size()-1] << endl;

  for(int i = 0; i < w.size() - 1; i++){
    ll before = w[i]; // マイナスして0にする分

    ll after = w[w.size()-1] - w[i]; // プラスしてrにする分 
    ll after_num = w.size() - i - 1;
    after = r * after_num - after;

    // cerr << "r: " << r << " before: " << before << " after: " << after << endl;


    if(before == after && before <= K){
      return true;
    } else {
      continue;
    }
  }

  return false;
}

int main(){
  cout << setprecision(10);
  int N; cin >> N;
  ll K; cin >> K;
  vector<ll> v(N);

  ll sum = 0;
  for(int i = 0; i < N; i++){
    cin >> v[i];
    sum += v[i];
  }

  auto list = divisor(sum);
  sort(list.begin(), list.end());

  ll ans = 1;

  for(int i = list.size()-1; i >= 0; i--){
    // K回以下で、list[i]で割れるようにできるか

    if(solve(v, K, list[i])){
      ans = list[i];
      break;
    }
  }

  cout << ans << endl;
}
