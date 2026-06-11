#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a,b,c;
	cin>>a>>b>>c;
	if(c-a-b>=0&&4*a*b<(c-a-b)*(c-a-b))cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
 } 