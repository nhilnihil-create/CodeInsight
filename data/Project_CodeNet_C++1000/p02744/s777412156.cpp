#include<bits/stdc++.h>//by btng_smith666 juruo
using namespace std;
int a[11],n,ans;
void dfs(int tmp,int maxn)//dfs 大法好！ 
{//两个函数量：tmp 临时变量，maxn 最大值 
	if(tmp>n)//如果 tmp>n 就可以出答案了 
	{
		for(int i=1;i<=n;i++)
			cout<<char(a[i]+96);//关于 ASCII 码珂以去百度找一下对照表，这里的 96 就是 'a'-1 ，注意这里要把这个数转为字符 
		cout<<endl;//再次强调 AT 的题要换行 
		return ;//结束程序 
	}
	for(int i=1;i<=maxn;i++)
		a[tmp]=i,dfs(tmp+1,maxn);//把 a[tmp] 赋值成 i ，搜索每位相同的情况 
	a[tmp]=maxn+1;//再赋值成 最大值 +1 
	dfs(tmp+1,maxn+1);//继续搜索另一种每位不同的情况 
}
int main()
{
	cin>>n;
	if(n==1)//如果 n=1 就只能是 a  
	{
		cout<<'a';
		return 0;
	}
	dfs(1,0);//从 1 开始 dfs 
	return 0;
}