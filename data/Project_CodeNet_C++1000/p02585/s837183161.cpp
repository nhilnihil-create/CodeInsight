#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 5e3 + 53;
int p[N], c[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin>>n>>k;
	for(int i = 1; i <= n; i++){
		cin>>p[i];
	}
	for(int i = 1; i <= n; i++){
		cin>>c[i];
	}
	ll ans = -2e18;
	for(int i = 1; i <= n; i++){
		int v = i;
		vector<ll> vec;
		while(p[v] != i){
			vec.push_back(c[v]);
			v = p[v];
		}
		vec.push_back(c[v]);
		int len = vec.size();
		for(int i = 1; i < len; i++){
			vec[i] += vec[i - 1];
		}
		for(int i = 0; i < len; i++){
			if(i == k)break;
			ll tmp = vec[i] + ((k - i - 1)/len)*max(vec.back(), 0LL);
			ans = max(ans, tmp);
		}
	}
	cout<<ans<<endl;
}