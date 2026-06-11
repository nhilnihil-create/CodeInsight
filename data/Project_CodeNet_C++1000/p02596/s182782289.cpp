#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
  int k;
  cin>>k;
  int sum=0;
  for(int i=1;i<(1e7);i++)
  {
      sum=(sum*10+7)%k;
      if(sum==0)
      {
          cout<<i<<endl;
          return 0;

      }
  }

   cout<<-1<<endl;


   return 0;
}
