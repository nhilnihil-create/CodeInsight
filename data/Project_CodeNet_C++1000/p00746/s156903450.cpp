#include<iostream>
using namespace std;
int n;
main()
{
	while(cin>>n,n)
	{
		int lx=0,rx=0,ly=0,ry=0;
		int x[200]={},y[200]={};
		for(int i=0;i<n-1;i++)
		{
			int a,d;cin>>a>>d;
			x[i+1]=d%2?x[a]:d?x[a]+1:x[a]-1;
			y[i+1]=d%2?d==1?y[a]-1:y[a]+1:y[a];
			lx=lx<x[i+1]?lx:x[i+1];
			ly=ly<y[i+1]?ly:y[i+1];
			rx=rx<x[i+1]?x[i+1]:rx;
			ry=ry<y[i+1]?y[i+1]:ry;
		}
		cout<<rx-lx+1<<" "<<ry-ly+1<<endl;
	}
}

