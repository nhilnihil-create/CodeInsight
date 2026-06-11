#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

int main(){
   int x;
   cin>>x;

   int ans=1000*(x/500)+5*(x%500/5);

   cout << ans << endl;
   return 0;
}
