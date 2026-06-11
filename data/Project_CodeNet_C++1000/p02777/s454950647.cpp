#include<bits/stdc++.h>
const int M=300000;//M=1e6+100;
typedef long long int ll;
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s,t,u;
	int a,b;
	cin>>s>>t>>a>>b>>u;
	if(s==u)
	{
		cout<<a-1<<" "<<b;
	}else cout<<a<<" "<<b-1;
	
}
	