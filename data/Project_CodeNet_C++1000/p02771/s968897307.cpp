#include <bits/stdc++.h>
using namespace std;

typedef long long  int   ll;

int main()
{ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,c,d=0;
    cin>>a>>b>>c;
    if(a==b&&a==c)cout<<"No";

  else  if(b==a&&b==c)cout<<"No";

 else if(c==b&&c==a)cout<<"No";
    else if(a!=b&&a!=c&&c!=b)cout<<"No";
      else cout<<"Yes";

    return 0;
}
