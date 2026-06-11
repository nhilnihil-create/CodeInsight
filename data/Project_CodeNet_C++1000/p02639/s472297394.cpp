#include<bits/stdc++.h>
using namespace std;
int main()
{
  vector <int> a;
  for(int i =0 ; i<5; ++i)
  {
    int temp;
    cin>>temp;
    a.push_back(temp);
  }
  int ans = 0;
  for(int i =0; i<5; ++i)
    if(a[i] == 0)
    {
      ans = ++i;
      break;
    }
  cout<<ans<<endl;
}
  