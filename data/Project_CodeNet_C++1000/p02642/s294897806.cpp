#include<bits/stdc++.h>

using namespace std;
using ll = long long;

class Osa_k {
private:
	int n;
	vector<int> factor;

	void dfs(int val, int idx ,vector<int>& ans, map<int,int>& mp,const vector<int> &facts) {
		if(idx == (int)facts.size()) {
			ans.push_back(val);
			return;
		}
		int v = facts[idx];
		for(int i = 0; i <= mp[v]; i++) {
			dfs(val, idx+1, ans, mp, facts);
			val *= v;
		}
	}

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
		map<int,int> mp = sieve(v);
		vector<int> factors;
		for(auto i : mp)factors.emplace_back(i.first);
		vector<int> ans;
		dfs(1, 0, ans, mp, factors);
		sort(ans.begin(), ans.end());
		return ans;
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

}fact(1000001);

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> in(1000001);
    for(int i = 0; i < n; i++)cin >> a[i], in[a[i]]++;
    int sum = 0;
 
    for(int i = 0; i < n; i++) {
        vector<int> num = fact.divisor(a[i]);
        int res = 0;
        for(int j = 0; j < num.size(); j++) {
            res += in[num[j]];
        }
        if(res == 1)sum++;
    }
    cout << sum << '\n';
}