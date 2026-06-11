#include<bits/stdc++.h>
using namespace std;
#define N 505

int n;
int a[N][N];

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	for(int i=1;i<n;i++,cout<<'\n')
	for(int j=i+1;j<=n;j++)
	{
		int c=0;
		while(!((i^j)&(1<<c))) c++;
		cout<<c+1<<' ';
	}
	
	return 0;
}