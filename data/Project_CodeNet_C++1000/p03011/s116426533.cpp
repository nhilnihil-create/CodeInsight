#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int a,b,c;
	cin>>a>>b>>c;
	cout<<a+b+c-max(max(a,b),c);
    return 0;
}
