#include<bits/stdc++.h>
using namespace std;
int main()
{
  int N,M;
  cin>>N>>M;
  if(N%2)
  {
    for(int i=0;i<M;i++)
      cout<<i+1<<" "<<N-i<<endl;
    return 0;
  }
  else
  {
    int X=1;
    while(X+X-1<N+1-X-X&&M)
    {
      M--;
      cout<<X<<" "<<N-X+1<<endl;
      X++;
    }
    N--;
    while(M)
    {
      M--;
      cout<<X<<" "<<N-X+1<<endl;
      X++;
    }
    return 0;
  }
}