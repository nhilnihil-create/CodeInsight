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
	int n;
	cin>>n>>s;
	if(n%2!=0) {
		cout<<"No";
		return 0;
	}
	for (int i = 0; i < n/2; ++i)
	{
		if(s[i]!=s[n/2+i]){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	

   return 0;
}
