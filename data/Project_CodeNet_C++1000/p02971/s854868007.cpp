#include <bits/stdc++.h>
using namespace std;

int main()
{
int N;scanf("%d\n",&N);
int A[N],maxA=0,secondmaxA=0,count=0;
for(int i=0;i<N;i++){scanf("%d\n",&A[i]);maxA=max(A[i],maxA);}
for(int i=0;i<N;i++){if(A[i]!=maxA)secondmaxA=max(A[i],secondmaxA);else count++;}
for(int i=0;i<N;i++)
{
  if(A[i]==maxA)
  {
    if(secondmaxA==0||count>1)printf("%d\n",maxA);
    else printf("%d\n",secondmaxA);
  }
  else printf("%d\n",maxA);
}  
}