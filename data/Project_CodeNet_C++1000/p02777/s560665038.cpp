#include<bits/stdc++.h>
using namespace std;
#define mx 1000000000000000000
#define ll long long int
//ll a[40001000];
//ll number[20],used[20];
int main()
{
   //char s[100],t[100],u[100];
   string s,t,u;
   ll x,y;
   cin >> s >> t;
   cin >> x >> y;
   cin >> u;
   ll count =0;
   for(ll i=0;i<s.size();i++)
   {
       if(s[i]==u[i])
        count =0;
       else
       {
           count =1;
           break;
       }
   }
   if(count ==0)
    cout << x-1 << " " << y << endl;
   else
    cout << x << " " << y-1 << endl;
    return 0;
}
