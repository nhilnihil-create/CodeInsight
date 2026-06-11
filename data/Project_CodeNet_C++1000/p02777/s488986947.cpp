#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s,t;
	cin>>s>>t;
	int num1,num2;
	cin>>num1>>num2;
	string p;
	cin>>p;
	if(p==s)
	 cout<<num1-1<<" "<<num2;
	else if(p==t)
	 cout<<num1<<" "<<num2-1;
	return 0;
}