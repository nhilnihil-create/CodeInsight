#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define SZ(X) ((int)(X).size())
#define endl "\n";
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n,k,j;
	vector<int> a;
	cin>>n>>k;
	for (int i = 0; i < n; ++i)
	{
		cin>>j;
		a.push_back(j);

	}
	sort(all(a));
	int cnt=0;
	for (int i = 0; i< n; ++i)
	{
		if(a[i]>=k){
		 cnt++;	
		}
	}
	cout<<cnt;

   return 0;
}
