#include <bits/stdc++.h>
#define reg register
#define ll long long
using namespace std;
int n,d,cnt;
int main()
{
//	freopen("1.in","r",stdoin)
	cin>>n>>d;
	for(reg int i=1;i<=n;i++)
	for(reg int j=10;j<=d;j++)
	{
		reg int x=j/10,x2=j%10;
		if(x*x2==i&&x>=2&&x2>=2)cnt++;
	}
	cout<<cnt<<endl;
}