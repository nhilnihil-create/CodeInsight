#include<bits/stdc++.h>
 using namespace std;
 #define ll long long int
 int main()
  { ll c,d,e,f,g,r,i,x=0,sum,l,v,aa,bb,y;
     ll n;
      cin>>n;
    ll a[n+1];
       for(i=1;i<=n;i++)
         cin>>a[i];
        for(i=1;i<=n;i++)
        { if(a[i]%2==1&&i%2==1)
            x++;
        }

      cout<<x<<endl;
  }
