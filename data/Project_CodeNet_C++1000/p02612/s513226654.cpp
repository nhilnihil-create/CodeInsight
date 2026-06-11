#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int N , r;
    
    cin>> N;
    
    r = (N % 1000);
    
    if(r==0)
       cout<<"0";
      else
      {
          cout<<(1000-r);
      }

    return 0;
}
