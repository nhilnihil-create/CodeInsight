#include <bits/stdc++.h>
#define ll long long
#define Start ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define fr first
#define sc second
#define PI 3.14159265
#define ullt unsigned long long int
using namespace std;
void solve(){
	int n,x,t;
	cin>>n>>x>>t;
	cout<<(n/x+(n%x>0))*t;
}	
int main()
{
	Start;

	int t = 1;
	//cin>>t;
	while (t--)
	{
		solve();
		cout << "\n";
	}
	return 0;
}
