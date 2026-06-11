#include<bits/stdc++.h>
using namespace std;

int main()
{
  int A,B;scanf("%d %d",&A,&B);
  double Ai=A*12.5,Aj=(A+1)*12.5,Bi=B*10,Bj=(B+1)*10;
  double I=max(Ai,Bi),J=min(Aj,Bj);
  int k;
  if((int)I-I==0)k=I;
  else k=(int)I+1;
  if(k<J)printf("%d",k);
  else printf("-1");
}