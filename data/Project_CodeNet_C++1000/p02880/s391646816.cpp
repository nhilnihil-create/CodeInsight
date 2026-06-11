#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,flg=0;
    cin>>n;

    for(i=1;i<10;i++)
    {
        if(n % i == 0 && n / i < 10)
        {
            flg++;
            break;
        }
    }
  
  if(flg == 1) cout<<"Yes";
  else cout<<"No";
}