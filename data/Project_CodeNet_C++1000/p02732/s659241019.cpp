#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

ll pc(int n){
   if(n<=1) return 0;
   return (ll)n*(n-1)/2;
}

int main(){
   int n;
   cin>>n;
   vector<int> a(n);
   rep(i, n) cin>>a[i];

   map<int, int> cnt;
   rep(i, n){
      cnt[a[i]]++;
   }
   ll tot=0;
   repit(it, cnt){
      tot+=pc(it->second);
   }

   rep(k, n){
      int c=cnt[a[k]];
      ll ans=tot -pc(c) +pc(c-1);
      cout<<ans<<endl;
   }

   return 0;
}
