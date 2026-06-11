#include<iostream>
using namespace std;
struct node{
	int p;
	int left;
	int right;
};
struct node tree[30];

void Preorder(int n)
{
	if(n==-1)
		return;
	cout<<" "<<n;
	Preorder(tree[n].left);
	Preorder(tree[n].right);
}

void Inorder(int n)
{
	if(n==-1)
		return;
	Inorder(tree[n].left);
	cout<<" "<<n;
	Inorder(tree[n].right); 
	
}

void Postorder(int n)
{
	if(n==-1)
		return;
	Postorder(tree[n].left);
	Postorder(tree[n].right); 
	cout<<" "<<n;
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		tree[i].p=tree[i].left=tree[i].right=-1;
	}
	for(int i=0;i<n;i++)
	{
		int p,l,r;
		cin>>p>>l>>r;
		tree[p].left=l;
		tree[p].right=r;
		if(l!=-1)
		{
			tree[l].p=p;	
		}
		if(r!=-1)
		{
			tree[r].p=p;
		}
	}
	int root=0;
	for(int i=0;i<n;i++)
	{
		if(tree[i].p==-1)
		{
			root=i;
			break;
		}
	}
	cout<<"Preorder"<<endl;
	Preorder(root);
	cout<<endl;
	cout<<"Inorder"<<endl;
	Inorder(root);
	cout<<endl;
	cout<<"Postorder"<<endl;
	Postorder(root);
	cout<<endl;
	
	return 0;
} 
