#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;scanf("%d",&N);
  int a[N];long long sum=0,suma=0;
  for(int i=0;i<N;i++){scanf("%d ",&a[i]);sum+=a[i];}
  pair<long long,long long> p[2];
  for(int i=0;i<N;i++)
  {
    suma+=a[i];
    if(suma<=sum-suma)p[0].first=suma,p[0].second=sum-suma;
    else {p[1].first=sum-suma,p[1].second=suma;break;}
  }
  printf("%lld",min(p[0].second-p[0].first,p[1].second-p[1].first));
}