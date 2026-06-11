#include <bits/stdc++.h>
#include<math.h>
using namespace std;
#define NMAX 1000000
int main()
{
int N,A;
cin>> N;
int v[N+1];
std::fill_n(v, N+1 , 0);
for(int i=2;i<=N;i++)
{
  cin>>A;
  v[A-1]++;
}
  for(int i=0;i<N;i++)
  {
     cout<<v[i]<<endl;
  }
}
