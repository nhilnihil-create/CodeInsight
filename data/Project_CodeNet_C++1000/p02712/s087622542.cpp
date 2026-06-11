#include<bits/stdc++.h>
using namespace std;
int main()

{
 long long a;
  cin>>a;
  long long s = 0;
  for(int i=1; i<=a; i++)
  {
    if(i%3!=0)
    {if(i%5!=0)
     s+=i;
    }
  }
  cout<<s;


}
