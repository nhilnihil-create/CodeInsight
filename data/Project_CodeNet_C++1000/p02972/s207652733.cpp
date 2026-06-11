#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n; cin>>n;
	vector<int> a(n + 1), b(n + 1);
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	for(int i = n; i >= 1; i--){
		int cnt = 0;
		for(int j = i*2; j <= n; j += i){
			cnt ^= b[j];
		}
		b[i] = cnt^a[i];
	}
	int m = accumulate(b.begin(), b.end(), 0);
	cout<<m<<'\n';
	for(int i = 1; i <= n; i++){
		if(b[i])cout<<i<<" ";
	}

	return 0;
}