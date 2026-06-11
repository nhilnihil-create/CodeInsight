#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a,b;
  int n=0,ans=1;
  cin>>a>>b;
  while(ans<b)
  {
    --ans;
    ans=ans+a;
    ++n;
  }
  cout<<n<<endl;
}
