#include<bits/stdc++.h>
using namespace std;

int main()
{
int A,B,M;scanf("%d %d %d",&A,&B,&M);
int ans=300000,an=300000;
vector<int> a(A);vector<int> b(B);
for(int i=0;i<A;i++){scanf("%d ",&a[i]);an=min(an,a[i]);}
for(int i=0;i<B;i++){scanf("%d ",&b[i]);ans=min(an+b[i],ans);}
vector<int> x(M);vector<int> y(M);vector<int> c(M);
for(int i=0;i<M;i++){scanf("%d %d %d",&x[i],&y[i],&c[i]);ans=min(ans,a[x[i]-1]+b[y[i]-1]-c[i]);}
printf("%d\n",ans);
}