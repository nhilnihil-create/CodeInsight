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
	int n,a;
	cin>>n;
	set<int> s;
	for (int i = 0; i < n; ++i)
		{
			cin>>a;
			s.insert(a);
		}	
    SZ(s)==n?cout<<"YES":cout<<"NO";
   return 0;
}
