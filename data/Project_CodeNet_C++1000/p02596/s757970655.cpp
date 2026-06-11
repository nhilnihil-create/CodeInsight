#include<bits/stdc++.h>
using namespace std;
void solve()
{
int k;
  cin>>k;
  int count=0;
  for(int i=1;i<1e7;i++)
  {
   
    count=(count*10+7)%k;
    if(count==0)
    {
    cout<<i;
      return;
    }
  } 
 cout<<-1;
}

int main()
{
solve();
  
}
