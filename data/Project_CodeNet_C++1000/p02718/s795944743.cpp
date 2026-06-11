#include <bits/stdc++.h>
using namespace std;

//#define int long long 
#define dou  double 
#define endl "\n"

const int MOD=1e9+7;

void solve()
{
	int n,i,sum=0,j,m,count=0;
	cin >> n >> m;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
		sum+=v[i];
	}
	int x=4*m;
	//int ax = sum/x;
	//cout << ax << '\n';
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		//cout << v[i] << '\n';
		if(v[i]>=ceil(sum/(4.0*m)))
			count++;
	}
	if(count>=m)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	solve();
}
