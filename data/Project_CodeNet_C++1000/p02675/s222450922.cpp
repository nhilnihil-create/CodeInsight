#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n;cin>>n;
	int m=n%10;
	if(m==2||m==4||m==5||m==7||m==9)
	cout<<"hon"<<"\n";
	if(m==0||m==1||m==6||m==8)
	cout<<"pon"<<"\n";
	if(m==3) cout<<"bon"<<"\n";
	return 0;
}