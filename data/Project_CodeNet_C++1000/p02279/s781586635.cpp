#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<cmath>
#include<cstdlib>
#include<typeinfo>
#include<sstream>
#include<list>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define fori(i,k,n) for(int i=k;i<(int)n;i++)
using namespace std;
int stringInt(string a)
{
	return atoi(a.c_str());
}
string intString(int a)
{
	stringstream ss;
	ss<<a;
	return ss.str();
}
vector<int> SieveOfEratosthenes(int x)
{
	vector<int> a;
	vector<int> b(x+1,0);
	for(int i=2;i<=x;i++)
	{
		if(b[i]==0)
		{
			a.push_back(i);
			for(int l=i;l<=x;l+=i)
			{
				b[l]=1;
			}
		}
	}
	return a;
}
struct node
{
	int p,l,r;
};
int main() {
	int n;
	node a[100005];
	cin>>n;
	rep(i,n)a[i].p=a[i].r=a[i].l=-1;
	rep(i,n)
	{
		int id,k,c;
		int now=-1;
		cin>>id>>k;
		rep(l,k)
		{
			cin>>c;
			a[c].p=id;
			if(a[id].l==-1)a[id].l=c;
			if(now!=-1)
			{
				a[now].r=c;
			}
			now=c;
		}
	}
	rep(i,n)
	{
		int d=0;
		int now=i;
		while(1)
		{
			if(a[now].p==-1)break;
			else
			{
				d++;
				now=a[now].p;
			}
		}

		printf("node %d: parent = %d, depth = %d, ",i,a[i].p,d);
		if(a[i].l==-1&&a[i].p!=-1)
		{
			cout<<"leaf, []"<<endl;;
		}
		else if(a[i].p==-1)
		{
			cout<<"root, [";
			if(a[i].l!=-1)
			{
				cout<<a[i].l;
				now=a[i].l;
				while(1)
				{
					if(a[now].r==-1)break;
					cout<<", "<<a[now].r;
					now=a[now].r;
				}
			}
			cout<<"]"<<endl;
		}
		else
		{
			cout<<"internal node, [";
			cout<<a[i].l;
			now=a[i].l;
			while(1)
			{
				if(a[now].r==-1)break;
				cout<<", "<<a[now].r;
				now=a[now].r;
			}
			cout<<"]"<<endl;
		}
	}

}