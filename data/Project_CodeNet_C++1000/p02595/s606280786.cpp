#include<bits/stdc++.h>
using namespace std;

void solve()
{ 
  int N,D;
  cin>>N>>D;
  int a;
    int b;
  
  
int minn=INT_MAX;
  int count=0;
  for(int i=0;i<N;i++)
  {
    
    cin>>a;
    cin>>b;
    if( sqrt(pow(a,2)+pow(b,2))<=D )
      count++;
    
  
  }
  cout<<count<<endl;
  

}
int main()
{

solve();
}