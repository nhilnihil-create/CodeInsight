#include <bits/stdc++.h>

using namespace std;
int main()
{
    int a,b,c,d,n,m,i;
    cin>>a>>b>>c>>d;
    while(d>0 && b>0)
    {
       if(a<=0 && c>0){
        cout<<"No"<<endl;
       break;
       }
       else if(a>=0 && c<=0)
       {
           cout<<"Yes"<<endl;
           break;
       }
       a-=d;
       c-=b;



    }

   return 0;
}
