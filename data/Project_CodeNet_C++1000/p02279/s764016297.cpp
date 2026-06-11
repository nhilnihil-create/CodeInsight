#include<iostream>
using namespace std;

#define NIL -1
struct node
{
	int left;
	int right;
	int parent;
};
struct node tree[100005];
int D[100005];
void rec(int u,int p)
{
	D[u]=p;
	if((tree[u].right)!=NIL)
		rec(tree[u].right,p);
	if((tree[u].left)!=NIL)
		rec(tree[u].left,p+1);
}

void print(int i)
{
	int j,c;
	cout<<"node "<<i<<": ";
	cout<<"parent = "<<tree[i].parent<<", ";
	cout<<"depth = "<<D[i]<<", ";
	if(tree[i].parent==NIL)
		cout<<"root, ";
	else if(tree[i].left==NIL)
		cout<<"leaf, ";
	else
		cout<<"internal node, ";
	cout<<"[";
	for(j=0,c=tree[i].left;c!=NIL;j++,c=tree[c].right)
	{
		if(j)
			cout<<", ";
		cout<<c;
	}
	cout<<"]"<<endl;
}
int main()
{
	int n;
	int num,c,l,r,nod;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		tree[i].parent=NIL;
		tree[i].left=NIL;
		tree[i].right=NIL;
	}
	for(int i=0;i<n;i++)
	{
		cin>>c>>num;
		for(int j=0;j<num;j++)
		{
			cin>>nod;
			if(j==0)
				tree[c].left=nod;
			else
				tree[l].right=nod;
			l=nod;
			tree[nod].parent=c;
		}
	}
	for(int i=0;i<n;i++)
	{
		if((tree[i].parent)==NIL)
		{
			r=i;
			break;
		}
	}
	rec(r,0);
	for(int i=0;i<n;i++)
		print(i);
	return 0;
}
