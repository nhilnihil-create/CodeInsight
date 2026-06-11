#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100000;

int n,a[N+9];

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
}

int ans0,ans[N+9][2];

void Get_ans(){
  sort(a+1,a+n+1);
  if (a[n-1]<=0){
	ans0=a[n];
	for (int i=1;i<n;++i){
	  ans[i][0]=ans0;ans[i][1]=a[i];
	  ans0-=a[i];
	}
	return;
  }
  ans0=a[n];
  for (int i=1;i<n-1;++i)
	if (a[n-i]>0){
	  ans[i][0]=a[1];ans[i][1]=a[n-i];
	  a[1]-=a[n-i];
	}else{
	  ans[i][0]=ans0;ans[i][1]=a[n-i];
	  ans0-=a[n-i];
	}
  ans[n-1][0]=ans0;ans[n-1][1]=a[1];
  ans0-=a[1];
}

void work(){
  Get_ans();
}

void outo(){
  printf("%d\n",ans0);
  for (int i=1;i<n;++i)
	printf("%d %d\n",ans[i][0],ans[i][1]);
}

int main(){
  into();
  work();
  outo();
  return 0;
}