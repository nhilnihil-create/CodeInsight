#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <stack>
#include <queue>
#include <list>
#include <stdio.h>
#include <algorithm>
#define MAX 100000
using namespace std;
typedef long long ll;
vector<int> G;
int a[1000001],ans;
void insertsort(int a[],int n,int g)
{
	int i,j;
	for(i=g;i<n;i++)
	{
		int tmp=a[i];
		j=i-g;
		while(j>=0&&a[j]>tmp){
			a[j+g]=a[j];
			j-=g;
			ans++;
		}
		a[j+g]=tmp;//复位 
	}
}//其实只有g和插入排序不同 
void shellsort(int a[],int n)
{
	for(int h=1;;){
		if(h>n) break;
		G.push_back(h);
		h=3*h+1;	
	}
	for(vector<int>::reverse_iterator it=G.rbegin();it!=G.rend();it++){
		insertsort(a,n,*it);
	}
}
int main(int argc, char *argv[]) {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	shellsort(a,n);
	printf("%d\n",G.size());
	for(int i=G.size()-1;i>=0;i--)
	{
		if(i==0) printf("%d\n",G[i]);
		else printf("%d ",G[i]);
	}
	printf("%d\n",ans);
	for(int i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
