#include<iostream>
#include<string>
using namespace std;


int main()
{
  int count=0,N,M,*H,A,B;
  bool *best;
  cin>>N>>M;
  
  H=new int[N];
  best=new bool[N];
  for(int i=0;i<N;i++)
  {
    cin>>H[i];
    best[i]=true;
  }
  for(int i=0;i<M;i++)
  {
    cin>>A>>B;
    A--;
    B--;
    if(H[A]>=H[B])
      best[B]=false;
    if(H[A]<=H[B])
      best[A]=false;
  }
  for(int i=0;i<N;i++)
    if(best[i])
      count++;
  
  cout<<count;
  
  delete[] H;
  delete[] best;
}