#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long modpow(long long a, long long b){
	long long ans = 1;
	while (b > 0){
		if (b % 2 == 1){
			ans *= a;
			ans %= MOD;
		}
		a *= a;
		a %= MOD;
		b /= 2;
	}
	return ans;
}
long long modinv(long long a){
	return modpow(a, MOD - 2);
}
vector<long long> mf = {1};
vector<long long> mfi = {1};
long long modfact(int n){
	if (mf.size() > n){
		return mf[n];
	} else {
		for (int i = mf.size(); i <= n; i++){
			long long next = mf.back() * i % MOD;
			mf.push_back(next);
			mfi.push_back(modinv(next));
		}
		return mf[n];
	}
}
long long modfactinv(int n){
	if (mfi.size() > n){
		return mfi[n];
	} else {
		return modinv(modfact(n));
	}
}
long long modbinom(int n, int k){
	if (n < 0 || k < 0 || k > n){
		return 0;
	} else {
		return modfact(n) * modfactinv(k) % MOD * modfactinv(n - k) % MOD;
	}
}
long long modperm(int n, int k){
  if (n < 0 || k < 0 || k > n){
    return 0;
  } else {
    return modfact(n) * modfactinv(n - k) % MOD;
  }
}
long long dfs(vector<vector<int>> &c, int K, int v = 0){
  long long ans = 1;
  if (v == 0){
    ans = modperm(K - 1, c[v].size());
  } else {
    ans = modperm(K - 2, c[v].size());
  }
  for (int w : c[v]){
    ans *= dfs(c, K, w);
    ans %= MOD;
  }
  return ans;
}
int main(){
  int N, K;
  cin >> N >> K;
  vector<vector<int>> E(N);
  for (int i = 0; i < N - 1; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  vector<int> p(N, -1);
  vector<vector<int>> c(N);
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : E[v]){
      if (w != p[v]){
        p[w] = v;
        c[v].push_back(w);
        Q.push(w);
      }
    }
  }
  cout << K * dfs(c, K) % MOD << endl;
}