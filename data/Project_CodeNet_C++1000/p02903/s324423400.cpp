#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=1000;

int n,m,a,b;

void into(){
  scanf("%d%d%d%d",&n,&m,&a,&b);
}

int ans[N+9][N+9];

void Get_ans(){
  for (int i=1;i<=b;++i)
	for (int j=1;j<=m;++j) ans[i][j]=1;
  for (int i=1;i<=n;++i)
	for (int j=1;j<=a;++j) ans[i][j]^=1;
}

void work(){
  Get_ans();
}

void outo(){
  for (int i=1;i<=n;++i){
	for (int j=1;j<=m;++j)
      putchar(ans[i][j]+'0');
    puts("");
  }
}

int main(){
  into();
  work();
  outo();
  return 0;
}