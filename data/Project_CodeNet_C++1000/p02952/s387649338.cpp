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
	int n,ans=0;
	cin>>n;
	for (int i = 1; i <= n; ++i)
	{
		if(SZ(to_string(i))%2!=0){
			ans++;
		}
	}
   cout<<ans; 	
   return 0;
}
