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
	string s;
	cin>>s;
	int n = SZ(s),ans=0;
	
	for (int i = 0; i < n/2; ++i)
	{
		if(s[i]!=s[n-i-1]){
			ans++;
		}
	}
	cout<<ans;
	

   return 0;
}
