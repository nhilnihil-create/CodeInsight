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

	int n, k;
	cin>>n>>k;
	string s;
	cin>>s;
	int ans = 1;
	for(int i = 1; i < n; i++){
		if(s[i] != s[i - 1])ans++;
	}
	ans = max(1, ans - 2*k);
	cout<<n - ans<<endl;

	return 0;
}