#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,c,d;
    cin>>n;
      d=n%1000;
    if(d!=0)
       {
            c = (1000-d);
       cout<<c<<"\n";
       }
    else
     cout<<d<<endl;
}
