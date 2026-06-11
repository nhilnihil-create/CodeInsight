#include<iostream>
using namespace std;
  void solve()
{
 string S,T;
     cin>>S>>T;
    T.pop_back();
  if(S==T)
  {
    cout<<"Yes"<<endl;
  }
    else
    {    cout<<"No"<<endl;
    }
}
int main()
{
   solve();
  return 0;
}
