#include<iostream>
#include<string>
using namespace std;


int main()
{
  int N,K,d,A,count=0;
  bool *b;
  cin>>N>>K;
  b=new bool[N];
  for(int i=0;i<N;i++)
    b[i]=false;
  for(int i=0;i<K;i++)
  {
    cin>>d;
    for(int j=0;j<d;j++)
    {
      cin>>A;
      b[A-1]=true;
    }
  }
  for(int i=0;i<N;i++)
    if(!b[i])
      count++;
  cout<<count;
  
  delete[] b;
}