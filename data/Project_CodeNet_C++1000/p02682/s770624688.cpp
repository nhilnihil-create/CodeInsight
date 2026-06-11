#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
signed int  a,b,c,d,e=0; cin>>a>>b>>c>>d;
 if(d>0){ e=min(d,a);d=d-min(d,a);}
 if(d>0){d=d-b;}
 if(d>0){e-=min(d,c);}
  cout<<e;
}


