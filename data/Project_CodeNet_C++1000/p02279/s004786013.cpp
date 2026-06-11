#include<iostream>
using namespace std;
#define maxx 100004
//树的左子右兄弟表示法 
struct node{
	int p;   //父结点 
	int l;   //最左边的子结点 
	int r;   //紧邻的兄弟结点 
};
struct node tree[maxx]; 
int depth[maxx];
int n;
/*
void Depth()
{
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		int k=i;
		while(tree[k].p!=-1)
		{
			cnt++;
			k=tree[k].p;
		}
		depth[i]=cnt;
	}
}*/
void Depth(int u,int p)
{
	depth[u]=p;
	if(tree[u].r!=-1)
		Depth(tree[u].r,p);
	if(tree[u].l!=-1)
		Depth(tree[u].l,p+1);
}
//NULL和0在计算机中的存储是一致的 
void printTree()
{
	for(int i=0;i<n;i++)
	{
		cout<<"node "<<i<<": parent = ";
		if(tree[i].p==-1)
			cout<<"-1";
		else cout<<tree[i].p;
		cout<<", depth = "<<depth[i]<<", ";
		if(depth[i]==0)
			cout<<"root, [";
		else if(tree[i].l==-1)
			cout<<"leaf, [";
		else cout<<"internal node, [";
		int kk=tree[i].l;
		if(kk!=-1)
		{
				
			cout<<tree[i].l;
			while(tree[kk].r!=-1)
			{
			
				cout<<", ";
				cout<<tree[kk].r;
				kk=tree[kk].r;
			}
		}
		cout<<"]"<<endl;
		
	}
}
int main()
{
	cin>>n;
	//结点信息初始化 
	for(int i=0;i<n;i++)
	{
		tree[i].l=tree[i].p=tree[i].r=-1;
	}
	// 
	for(int i=0;i<n;i++)
	{
		int id;
		cin>>id;
		int nn;
		cin>>nn;
		//degree[i]=nn;
		for(int j=0;j<nn;j++)
		{
			int tt,pnn;
			cin>>tt;
			tree[tt].p=id;
			if(j==0)
				tree[id].l=tt;
			if(j!=0)
				tree[pnn].r=tt;
			pnn=tt;
		}
	}
	//cout<<"1111"<<endl;
	int r;
	for(int i=0;i<n;i++)
	{
		if(tree[i].p==-1)
		{
			r=i;
			break;
		}
	}
	Depth(r,0);
	//cout<<"1111"<<endl;
	printTree();
	return 0;
} 
