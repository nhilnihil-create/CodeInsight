#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100000;

int n;

void into(){
  scanf("%d",&n);
}

int ca,ans[N*2+9][2];

void Get_ans(){
  if ((n&-n)==n) return;
  for (int i=3;i<=n;i+=2){
	int x=i-1,y=i;
	ans[++ca][0]=x;ans[ca][1]=y;
	ans[++ca][0]=x+n;ans[ca][1]=y+n;
	ans[++ca][0]=1;ans[ca][1]=x;
	ans[++ca][0]=1;ans[ca][1]=y+n;
  }
  ans[++ca][0]=n+1;ans[ca][1]=3;
  if (n&1) return;
  int x=n&-n,y=n-x;
  ans[++ca][0]=n;ans[ca][1]=x;
  ans[++ca][0]=n<<1;ans[ca][1]=y+n+1;
}

void work(){
  Get_ans();
}

void outo(){
  if ((n&-n)==n) puts("No");
  else{
	puts("Yes");
    for (int i=1;i<n<<1;++i)
	  printf("%d %d\n",ans[i][0],ans[i][1]);
  }
}

int main(){
  into();
  work();
  outo();
  return 0;
}