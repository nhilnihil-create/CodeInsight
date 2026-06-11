#include<bits/stdc++.h>
using namespace std;
int n,m,q,a[55],b[55],c[55],d[55],slot[20],has,flag[15];
void f(int k,int las)
{
	if(k>n)
	{
		int now=0;
		//for(int i=1;i<=n;i++) cout<<slot[i]<<" ";
		for(int i=1;i<=q;i++)
		{
			if(slot[b[i]]-slot[a[i]]==c[i]) now+=d[i];
		}
		//cout<<" , now= "<<now<<endl<<"========"<<endl;
		has=max(has,now);
		return;
	}
	for(int i=las;i<=m;i++)
	{
		slot[k]=i;
		f(k+1,i);	
	}
}
int main()
{
	cin>>n>>m>>q;
	for(int i=1;i<=q;i++) cin>>a[i]>>b[i]>>c[i]>>d[i];
	f(1,1);
	cout<<has<<endl;
}