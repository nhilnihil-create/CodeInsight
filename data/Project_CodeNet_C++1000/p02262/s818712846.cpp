
#include<bits/stdc++.h>

using namespace std;

const int maxn=1e6+5;

int s[maxn],n,cnt;
vector<int>v;

void insertionsort(int g)
{
	for(int i=g;i<n;i++){
		int v=s[i],j=i-g;
		while(j>=0&&s[j]>v){
			s[j+g]=s[j];
			j-=g;
			cnt++;
		}
		s[j+g]=v;
	}
}

void shellsort()
{
	for(int h=1;;){
		if(h>n){
			break;
		}
		v.push_back(h);
		h=h*3+1;
	}
	int len=v.size()-1;
	for(int i=len;i>=0;i--){
		insertionsort(v[i]);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	shellsort();
	cout<<v.size()<<endl;
	for(int i=v.size()-1;i>=0;i--){
		printf("%d",v[i]);
		if(i){
			printf(" ");
		}
	}
	printf("\n");
	printf("%d\n",cnt);
	for(int i=0;i<n;i++){
		printf("%d\n",s[i]);
	}
	return 0;
}
/*
5
5 1 4 3 2
*/
