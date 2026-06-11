#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#define PI 3.14159265359
typedef long long ll;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
using namespace std;


ll llmin(ll x, ll y){
	if (x < y) return x;
	return y;
}

ll llmax(ll x, ll y){
	if (x > y) return x;
	return y;
}

vector<int> graph[100001];
ll fact[100001];
bool visited[100001];
ll n, k;

ll modpow(ll a, ll x){
	ll res = 1;
	while (x > 0){
		if (x & 1) res = res * a % MOD;
		a = a * a % MOD;
		x >>= 1;
	}
	return res;
}

ll modinv(ll a){
	return modpow(a, MOD-2);
}

ll nPr(ll x, ll y){
	return fact[x]*modinv(fact[x-y])%MOD;
}

ll dfs(int now){
	visited[now] = true;
	int siz = graph[now].size();
	if (now != 1 && siz == 1) return 1;
	ll ans = 1;
	if (now == 1){
		if (siz > k-1) return 0;
		ans *= nPr(k-1, siz);
		ans %= MOD;
	}else{
		if (siz > k-1) return 0;
		ans *= nPr(k-2, siz-1);
		ans %= MOD;
	}
	for (auto x : graph[now]){
		if (!visited[x]){
			ans *= dfs(x);
			ans %= MOD;
		}
	}
	return ans;
}

int main(){
	cin >> n >> k;
	for (int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	fact[0] = 1;
	for (int i = 1; i <= 100000; i++){
		fact[i] = fact[i-1]*i;
		fact[i] %= MOD;
	}
	if (n == 1){
		cout << k << endl;
		return 0;
	}
	cout << k*dfs(1)%MOD << endl;
	
	return 0;
}
