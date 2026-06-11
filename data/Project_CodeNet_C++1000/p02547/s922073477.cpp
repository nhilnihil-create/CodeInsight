#include "bits/stdc++.h"
using namespace std;
#define MODULO 1000000007
#define PI 3.14159265359
typedef long long int ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int ct=0;
	int flag=0;
	while(n--)
	{
		int a,b;
		cin>>a>>b;
		if(a==b)
		ct++;
		else
		ct=0;
		if(ct==3)
		{
			flag=1;
			cout<<"Yes";
			break;
		}
	}
	if(flag==0)
	cout<<"No"<<endl;
    return 0;
}
