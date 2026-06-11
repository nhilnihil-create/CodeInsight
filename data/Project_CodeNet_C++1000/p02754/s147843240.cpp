#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   ll n, a, b;
   cin>>n>>a>>b;

   ll l=n/(a+b);
   ll m=n%(a+b);
   ll ans=a*l + min(a, m);

   cout<<ans<<endl;
   return 0;
}
