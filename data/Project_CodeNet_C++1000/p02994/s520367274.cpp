#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
bool cmp(int lhs,int rhs) {
	return abs(lhs)<abs(rhs);
}
int abs(int x) {
	if(x<0)return -x;
	return x;
}
int main(){
  int N,L;
  scanf("%d %d",&N,&L);
  int a[200+5];
  for(int i =1;i<=N;i++){
    a[i] = L+i-1;
  }
  sort(a+1,a+N+1,cmp);
  int sum=0;
  for(int i=2;i<=N;i++)
	sum+=a[i];
  printf("%d\n",sum);
  return 0;
}
