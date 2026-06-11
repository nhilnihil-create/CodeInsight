#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m,d,x;
    int count=0;
    cin>>m>>d;

    for(int i=1;i <= m;i++)
    {
        for(int j=1;j <= d;j++)
        {
          x = j/10;
          if(j%10 >= 2)
          {
           if(x >= 2)
           {
             if(j%10*x == i)
             count++;
           }
          }
        }
    }

    cout<<count<<endl;

    return 0;
} 