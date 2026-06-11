#include <bits/stdc++.h>
#include<math.h>
using namespace std;
#define NMAX 1000000
int main()
{
int N,M,S=0;
int *A;
cin>>N>>M;
A=new int(M);
for(int i=0;i<M;i++)
{
  cin>>A[i];
}
for (int i=0; i<M ; i++)
{
  S+=A[i];
}
if(S>N)
{
  cout<<"-1"<<endl;
}
else {
  cout<<N-S;
}
}

