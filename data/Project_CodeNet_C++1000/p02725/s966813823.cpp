#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

int main(){
   int k, n;
   cin>>k>>n;
   vector<int> a(n);
   rep(i, n) cin>>a[i];

   int mx=0;
   rep(i, n){
      if(i==n-1) mx=max(mx, k+a[0]-a[n-1]);
      else mx=max(mx, a[i+1]-a[i]);
   }

   cout << k-mx << endl;
   return 0;
}
