#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<locale.h>
#include<set>
#include<stack>
#include<queue>
using namespace std;


int pare[200005]; //親
int rak[200005]; //深さ

//n要素で初期化
void init(int n)
{
//初期化の段階では親は自分自身、深さは0
	for(int i=0;i<n;i++)
	{
		pare[i]=i;
		rak[i]=0;
	}
}

//木の根を求める
//親に繋ぎつつ再帰処理
int find(int x)
{
	if(pare[x]==x){return x;}
	else{return pare[x]=find(pare[x]);}
}

//xとyの属する集合を併合
void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y){return ;}
	if(rak[x]<rak[y]){pare[x]=y;}//小さい木を子にする
	else{pare[y]=x;if(rak[x]==rak[y]){rak[x]++;} }
}

//xとyが同じ集合か否か
bool same(int x,int y)
{
	return find(x)==find(y);
}

int main()
{
int fin[200005]={};
int ans=0;
int n,m,a,b;
init(200005);
scanf("%d %d",&n,&m);
for(int i=0;i<m;i++)
{
	scanf("%d %d",&a,&b);
	unite(a,b);
}

for(int i=1;i<=n;i++)
{
	//printf("%d %d\n",i,find(i));
	fin[find(i)]++;
}
for(int i=1;i<=n;i++)
{
	if(ans<fin[i]){ans=fin[i];}
}
printf("%d",ans);

}
