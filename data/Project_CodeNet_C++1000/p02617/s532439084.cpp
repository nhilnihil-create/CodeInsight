#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int
#define P pair<int, int>

template<typename T>
struct BBIT {
	int n;
	vector<T> d, dd;
	BBIT(int n=0):n(n),d(n+1),dd(n+1) {}
	void add(int i, T x=1) {
		i++;
		for (int j=i; j <= n; j += j&-j) {
			d[j] += x;
			dd[j] += x*(j-i+1);
		}
	}
	T sum(int i) {
		i++;
		T x = 0;
		for (; i; i -= i&-i) {
			x += d[i];
		}
		return x;
	}
	T ssum(int i) {
		i++;
		T x = 0;
		for (int j=i; j; j -= j&-j) {
			x += dd[j] + d[j]*(i-j);
		}
		return x;
	}
};

int main(){
	int n;
	cin>>n;
	vector<int> e[200000];

	vector<P> uvs;
	rep(i, n-1){
		int u, v;
		cin>>u>>v; u--; v--;
		uvs.push_back(make_pair(u, v));
		uvs.push_back(make_pair(v, u));
	}
	sort(uvs.begin(), uvs.end());
	for(P p : uvs){
		e[p.first].push_back(p.second);
	}

	ll sum=0;
	BBIT<ll> dp(n);
	rep(r, n){
		int d=1;
		for(int u : e[r]){
			if(u>r) break;
			d--;
		}
		dp.add(0, d);
		int i=0;
		for(int u : e[r]){
			if(u>r) break;
			if(u+1<n) dp.add(u+1, 1);
			d++;
		}
		if(r+1<n) dp.add(r+1, -1);
		sum+=dp.ssum(n-1);
	}
	cout<<sum<<endl;

	return 0;
}
