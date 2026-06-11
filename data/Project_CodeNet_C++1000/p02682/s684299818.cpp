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
	int a,b,c,k;
	cin>>a>>b>>c>>k;
	if (a>=k) cout<<k;
	else if(a+b>=k) cout<<a;
	else cout<<a-(k-a-b);
		

   return 0;
}
