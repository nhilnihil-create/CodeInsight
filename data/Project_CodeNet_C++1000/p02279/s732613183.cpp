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
int dep(int i)
{
	int d=0;
	while(T[i].parent!=-1)
	{
		i=T[i].parent;
		d++;
	}
	return d;
}
void print(int i)
{
	printf("node %d: parent = %d, depth = %d, ",i,T[i].parent,dep(i));
	if(T[i].parent==-1)
	printf("root, ");
	else if(T[i].left==-1)
	printf("leaf, ");
	else
	printf("internal node, ");
	printf("[");
	for(int j=0,c=T[i].left;c!=-1;c=T[c].right,j++)
	{
		if(j)
		printf(", ");
		printf("%d",c);
	}
	printf("]\n");
}
int main()
{
	int n,id,k,c,p,r,l;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		T[i].left=-1;
		T[i].parent=-1;
		T[i].right=-1;
	}
	for(int i=0;i<n;i++)
	{
		cin>>id>>k;
		for(int j=0;j<k;j++)
		{
			cin>>c;
			if(j==0)
			T[id].left=c;
			else
			T[l].right=c;
			l=c;
			T[c].parent=id;
		}
	}
	for(int i=0;i<n;i++)
	print(i);
	return 0;
}
