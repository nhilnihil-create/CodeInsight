#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n+1),b(n);
	for(auto &i:a)cin >> i;
	for(auto &i:b)cin >> i;
	ll ans =0;
	for(int i  =0;i<n;i++)
	{
		int now = min(a[i],b[i]);
		a[i] -= now;
		b[i] -= now;
		ans += now;

		now = min(a[i+1],b[i]);
		a[i+1] -= now;
		ans += now;
	}
	cout<<ans<<endl;
}
