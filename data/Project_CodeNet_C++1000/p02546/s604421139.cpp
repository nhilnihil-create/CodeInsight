#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()

void solve()
{
 string a;
 cin>>a;
  int l=a.length();
  if(a[l-1]=='s'){cout<<a<<"es"<<endl;}
  else{cout<<a<<"s"<<endl;}
}

int main()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

        solve();

    return 0;
}

