#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int x,y,A,B,C;
struct node{
	int c;
	long long p;
};
node a[300030];
int cnt;

bool cmp(node X,node Y){
	return X.p>Y.p;
}

int main(){
	cin>>x>>y>>A>>B>>C;
	
	for (int i=1;i<=A;i++){
		long long p;
		scanf("%lld",&p);
		node t;
		t.c=1;
		t.p=p;
		a[++cnt]=t;
	}
	for (int i=1;i<=B;i++){
		long long p;
		scanf("%lld",&p);
		node t;
		t.c=2;
		t.p=p;
		a[++cnt]=t;
	}
	for (int i=1;i<=C;i++){
		long long p;
		scanf("%lld",&p);
		node t;
		t.c=3;
		t.p=p;
		a[++cnt]=t;
	}
	sort(a+1,a+cnt+1,cmp);
	long long ans = 0;
	
	int nx=0,ny=0,num=0;
	for (int i=1;i<=cnt;i++){
		node t = a[i];
		if (t.c==1){
			if (nx==x) continue;
			nx++;
		}
		else if (t.c==2){
			if (ny==y) continue;
			ny++;
		}
		num++;
		ans+= t.p;
		if (num==x+y) break;
	}
	
	cout<<ans<<endl;
	return 0;
}