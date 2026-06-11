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
	int x,y;
	cin>>x>>y;
	for (int c = 0; c <=x; ++c)
	{
		 int t = x-c;
		 if(2*c+4*t==y){
		 	cout<<"Yes";
		 	return 0;
		 }

	}
	cout<<"No";
	

   return 0;
}
