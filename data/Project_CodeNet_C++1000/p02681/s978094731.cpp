#include<iostream>
using namespace std;
string S,T;
void input()
{
  cin>>S>>T;
}
  void solve()
{
 
    T.pop_back();
  if(S==T)
  
    cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
  
}
int main()
{
  input();
   solve();
  return 0;
}
