#include <bits/stdc++.h>
#define ll long long int
using namespace std;


int  main()
{


#ifndef ONLINE_JUDGE
freopen("i.txt", "r", stdin);
freopen("o.txt", "w", stdout);
#else
// online submission

#endif
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  ll maxi=max(a*c,b*d);
  maxi=max(max(maxi,a*d),b*c);
  cout<<maxi<<endl;



    }






