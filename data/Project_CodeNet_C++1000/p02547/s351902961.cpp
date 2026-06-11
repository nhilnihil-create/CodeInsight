#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int n,counts=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int x,y; 
		scanf ("%d%d",&x,&y);
		if (x==y) counts++;
		else counts=0;
		if (counts==3) break;
	}
	if (counts==3) cout<<"Yes"<<endl;
	else cout<<"No\n"<<endl;
	return 0;
}