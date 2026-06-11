#include "iostream"
#define max 100005
#define nil -1
using namespace std;

struct node 
{
	int p,l,r;
}t[max];
int n,d[max];
void pri(int u)
{
	int i,c;
	cout<<"node "<<u<<": ";
	cout<<"parent = "<<t[u].p<<", ";
	cout<<"depth = "<<d[u]<<", ";
	
	if(t[u].p==nil)cout<<"root, ";
	else if(t[u].l==nil)cout<<"leaf, ";
	else cout<<"internal node, ";
	
	cout<<"[";
	for(i =0,c=t[u].l;c!=nil;i++,c=t[c].r)
	{
		if(i)cout<<", ";
		cout<<c;
	}
	cout<<"]"<<endl;
	
}

///递归地求深度
int rec(int u,int p)
{
	d[u]=p;
	if(t[u].r!=nil)rec(t[u].r,p);//右侧兄弟设置为相同深度；
	if(t[u].l!=nil)rec(t[u].l,p+1);//最左侧子节点的深度设置为自己的深度+1；
}
int main()
{
	int i,j,d,v,c,l,r;
	cin>>n;
	for(i=0;i<n;i++)t[i].p=t[i].l=t[i].r=nil;
	for(i=0;i<n;i++)
	{
		cin>>v>>d;
		for(j=0;j<d;j++)
		{
			cin>>c;
			if(j==0)t[v].l=c;
			else t[l].r=c;
			l=c;
			t[c].p=v;
		}
	}
	for(i=0;i<n;i++)
	{
		if(t[i].p==nil)r=i;
	}
	rec(r,0);
	for(i=0;i<n;i++)pri(i);
	
	return 0;
}
