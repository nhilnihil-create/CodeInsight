#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vec;

struct node
{
	int fa,dep;
	vec son;
	node()
	{
		fa=-1;
		dep=0;
		son.clear();
	}
}T[100100];

int main()
{ 
	//freopen("out.txt","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int id,ns;
		scanf("%d%d",&id,&ns);
		for(int j=0;j<ns;j++)
		{
			int t;
			scanf("%d",&t);
			T[id].son.push_back(t);
			T[t].fa=id;
		}
	}
	queue<int> que;
	for(int i=0;i<n;i++)
		if(T[i].fa==-1)
		{
			for(int j=0;j<T[i].son.size();j++)
				que.push(T[i].son[j]);
			break; 
		}
	while(!que.empty())
	{
		int t=que.front();que.pop();
		T[t].dep=T[T[t].fa].dep+1;
		for(int i=0;i<T[t].son.size();i++)
			que.push(T[t].son[i]);
	}
	for(int i=0;i<n;i++)
	{
		printf("node %d: parent = %d, depth = %d, ",i,T[i].fa,T[i].dep);
		if(T[i].fa==-1)
			printf("root, ");
		else if(T[i].son.size()==0)
			printf("leaf, ");
		else printf("internal node, ");
		for(int j=0;j<T[i].son.size();j++)
			printf("%c%d%c",j==0?'[':' ',T[i].son[j],j+1==T[i].son.size()?']':',');
		if(T[i].son.size()==0) printf("[]");
		printf("\n");
	}
	return 0;
}