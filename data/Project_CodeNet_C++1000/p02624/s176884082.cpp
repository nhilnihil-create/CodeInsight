#include<bits/stdc++.h>

using namespace std;
using ll = long long;



class Osa_k {
private:
	int n;
	vector<int> factor;
public:

	//O(NloglogN)
	Osa_k(int _n):n(_n) {
		factor.assign(n, 0);
		iota(factor.begin(), factor.end(), 0);
		for(int i = 2; i*i < n; i++) {
			if(factor[i] < i)continue;
			for(int j = i * i; j < n; j += i) {
				if(factor[j] == j)factor[j] = i;
			}
		}
	}

	//O(logV)
	map<int, int> sieve(int v) {
		map<int, int> ret;
		while(v != factor[v]) {
			ret[factor[v]]++;
			v /= factor[v];
		}
		if(v != 1)ret[v]++;
		return ret;
	}

	vector<int> divisor(int v) {
		
	}


	//O(N)
	vector<int> get_list() {
		vector<int> prime;
		for(int i = 2; i < n; i++)if(factor[i] == i)prime.emplace_back(i);
		return prime;
	}

	//O(1)
	bool is_prime(int v) {
		if(v <= 1)return false;
		return (factor[v] == v);
	}

}fact(10000001);


int main()
{
	int n; cin >> n;
	ll sum = 0;
	for(int i = 1; i <= n; i++) {
		auto v = fact.sieve(i);
		ll ans = 1;
		for(auto j : v)ans *= j.second+1;
		sum += ans * i;
	}
	cout << sum << endl;
}