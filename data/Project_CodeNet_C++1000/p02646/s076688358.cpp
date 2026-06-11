#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
   ll a,v,b,w,t;
   cin>>a>>v>>b>>w>>t;
   if(a>=0)
   {
       if(b>=0)
       {
           if(a+v*t>=b+w*t)
            cout<<"YES"<<endl;
           else
            cout<<"NO"<<endl;
       }
       else
       {


           if(a-v*t<=b-w*t)
            cout<<"YES"<<endl;
           else
            cout<<"NO"<<endl;
       }
   }
       else
       {
           if(b>=0)
           {
               if(a+v*t>=b+w*t)
                cout<<"YES"<<endl;
               else
                cout<<"NO"<<endl;
           }
           else
            if(a-v*t<=b-w*t)
              cout<<"YES"<<endl;
           else
            cout<<"NO"<<endl;
       }


 return 0;
}
