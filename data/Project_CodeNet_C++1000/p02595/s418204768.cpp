#include<iostream>
using namespace std;

int main()
{
  int64_t N,D,x,y,ret=0;
  cin>>N>>D;
  for(int i=0;i<N;i++)
  {
      cin>>x>>y;
      if(x*x+y*y<=D*D)
      ret++;
  }
  cout<<ret<<endl;
    return 0;
}
