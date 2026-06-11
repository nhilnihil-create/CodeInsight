#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

vector<pair<ll,ll>> prime;
vector<ll> can;
void DFS(int cnt,ll res) {
  if (cnt == prime.size()) {
    can.push_back(res);
    return ;
  } else {
    ll x = 1;
    for (int i = 0; i <= prime[cnt].second; i++) {
      DFS(cnt+1,res*x);
      x *= prime[cnt].first;
    }
  }
}

int main() {
  ll N,K;
  cin >> N >> K;
  ll A[N];
  ll sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    sum += A[i];
  }

  // 素因数分解
  int cnt = -1;
  for (int i = 2; i * i <= sum; i++) {
    if (sum % i == 0) {
      prime.push_back(make_pair(i,0));
      cnt++;
      while (sum % i == 0) {
        sum /= i;
        prime[cnt].second++;
      }
    }
  }
  if (sum != 1) {
    prime.push_back(make_pair(sum,1));
  }

  DFS(0,1LL);
  ll ans = 1;
  ll num = 0;
  vector<pair<ll,ll>> p;

  for (int i = 0; i < can.size(); i++) {
    num = 99999999999999;
    p.clear();
    if (can[i] == 1) {
      continue;
    }
    for (int j = 0; j < N; j++) {
      if (A[j] % can[i] != 0) {
        p.push_back(make_pair(can[i] - (A[j] % can[i]),A[j] % can[i]));
      }
    }
    if (p.size() == 0) {
      ans = max(can[i],ans);
      continue;
    }
    sort(p.begin(),p.end());
    ll R1[p.size()];
    ll R2[p.size()];
    R1[0] = p[0].first;
    R2[p.size()-1] = p[p.size()-1].second;
    for (int j = 1; j < p.size(); j++) {
      R1[j] = R1[j-1] + p[j].first;
    }
    for (int j = p.size() - 2; j >= 0; j--) {
      R2[j] = R2[j+1] + p[j].second;
    }
    
    for (int j = 0; j < p.size() - 1; j++) {
      if (R1[j] == R2[j+1]) {
        num = R1[j];
        break;
      }
    }
    if (num <= K) {
      ans = max(can[i],ans);
    }
  }
  cout << ans << endl;
  return 0;
}