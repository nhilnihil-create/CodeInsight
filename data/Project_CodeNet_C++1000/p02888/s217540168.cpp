#include<bits/stdc++.h>
#define ll long long
#define MAX 1000005
#define MOD (ll)(1e9+7)
using namespace std;

vector<int> a;

int main()	
{
	int n;
	cin >> n;
	a.resize(n);
	for(int i=0; i<n; i++)	cin >> a[i];
	sort(a.begin(),a.end());
	int ans=0;
	for(int i=0; i<n-1; i++)	{
		for(int j=i+1; j<n; j++)	{
			int x=a[i]+a[j];
			auto it=lower_bound(a.begin()+j+1,a.end(),x);
			--it;
			int d=it-(a.begin()+j);
			ans+=d;
		}
	}
	cout << ans << endl;
	return 0;
}