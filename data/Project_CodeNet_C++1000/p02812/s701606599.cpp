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
	int n,cnt=0;
	cin>>n;
	string s;
	cin>>s;
	for (int i = 3; i <=n; ++i)
		{
			if(s[i-3]=='A'&&s[i-2]=='B'&&s[i-1]=='C'){
				cnt++;
			}
		}	
		cout<<cnt;
   return 0;
}
