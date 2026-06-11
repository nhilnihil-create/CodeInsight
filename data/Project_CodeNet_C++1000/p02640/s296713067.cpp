#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define pb push_back
#define endl "\n"

int main()
{	
	FIO;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ll x,y;
	cin>>x>>y;

	if(y%2 == 0 && y>=2*x && y<=4*x) cout<<"Yes\n";
	else cout<<"No\n";

	return 0;
	
}