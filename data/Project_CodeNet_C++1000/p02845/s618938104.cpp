#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main()
{
long long N,ans=1;scanf("%lld",&N);
vector<int> colo(3,0);vector<int> A(N);
for(int i=0;i<N;i++)
{
  scanf("%d",&A[i]);int a=0;
  for(int j=0,k=1;j<3;j++)if(colo[j]==A[i]){if(k==1){colo[j]++;k--;}a++;}
  ans=ans*a%MOD;
}
printf("%d\n",ans);
}