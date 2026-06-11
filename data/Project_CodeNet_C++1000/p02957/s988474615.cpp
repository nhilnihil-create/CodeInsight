#include<bits/stdc++.h>
using namespace std;

long long int a,b;

signed main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>a>>b;
	if ((a+b)%2!=0) cout<<"IMPOSSIBLE";else cout<<(a+b)/2;
}
