#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int maxn=-1;
int main()
{
	int n,m,sum;
	cin>>n>>m;
	maxn=max(n,m);
	cin>>sum;
	cout<<(sum-1)/maxn+1;
}