#include<iostream>
using namespace std;
int main()
{
   int x,y; cin>>x>>y;
   if(y&1)
     cout<<"No\n";
  else{
    int crane,fox;
    fox = 2*x;
    crane = 4*x;
    if(y > crane || fox > y)
      cout<<"No\n";
    else
      cout<<"Yes\n";
    
  }
    return 0;
}