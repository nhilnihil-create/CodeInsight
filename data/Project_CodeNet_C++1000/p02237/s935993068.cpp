#include<cstdio>
#include<array>
using namespace std;
const int MAX_V = 100;
array<array<int,MAX_V>,MAX_V> ary{0};
int main(){
  int n;scanf("%d",&n);
  for(int i=0;i<n;i++){
    int u;scanf("%d",&u);
    int k;scanf("%d",&k);
    for(int j=0;j<k;j++){
      int v;scanf("%d",&v);
      ary[v-1][u-1]=1;
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      printf(j==n-1?"%d\n":"%d ",ary[j][i]);
    }
  }
}