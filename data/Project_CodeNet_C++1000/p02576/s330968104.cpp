#include<iostream>
using namespace std;
int main()
{
  int N,X,T;
  cin>>N>>X>>T;
  int count=T;
  for(int i=X;i<N;i+=X)
  { 
    count+=T;
  }
  cout<<count<<endl;
  return 0;
}