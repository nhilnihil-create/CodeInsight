#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, c=0;

    cin >> t;

      int a[t],i;
      int b[t];
      for(i=0;i<t;i++)
      {
          cin>> a[i];
          b[i] = a[i];
      }
      sort(b,b+t);
      for(i=0;i<t;i++)
      {
          if(a[i]!=b[i])
            c=c+1;
          if(c>2)
          {
              cout<<"NO";
              return 0;
          }
      }
      cout << "YES";

}
