#include<cstdio>
#include<set>
#include<iostream>
#include <iterator>
#include <utility>
#include<map>
#define max 100005
using namespace std;
struct tree
{
	int parent;
	int left;
	int  right;
};
struct tree T[max];
void pre(int u)
{
	if(u==-1)
	return;
	cout<<" "<<u;
	pre(T[u].left);
	pre(T[u].right);
}
void ino(int u)
{
	if(u==-1)
	return;
	ino(T[u].left);
	cout<<" "<<u;
	ino(T[u].right);
}
void pos(int u)
{
	if(u==-1)
	return;
	pos(T[u].left);
	pos(T[u].right);
	cout<<" "<<u;
}
int main()
{
	int n;
	int id,left,right;
	cin>>n;
	for(int i=0;i<n;i++)
	T[i].parent=-1;
	for(int i=0;i<n;i++)
	{
		cin>>id>>left>>right;
		T[id].left=left;
		T[id].right=right;
	
		if(left!=-1)
		T[left].parent=id;
		if(right!=-1)
		T[right].parent=id;
	}
	int root;

	for(int i=0;i<n;i++)
		if(T[i].parent==-1)
			root=i;
	
	cout<<"Preorder"<<endl;
		pre(root);
	cout<<endl;
	
	cout<<"Inorder"<<endl;
		ino(root);
	cout<<endl;
	
	cout<<"Postorder"<<endl;
		pos(root);
	cout<<endl;
	
	return 0;
}
