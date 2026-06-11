#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a,b,c,d;
	cin>>b>>a>>d>>c;
	int num1=ceil(d/float(a));
	int num2=ceil(b/float(c));
	if(num1<=num2)
	 cout<<"Yes";
	else
	 cout<<"No";
	return 0;
	
}