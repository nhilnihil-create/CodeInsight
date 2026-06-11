#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

int main(){
   int n, d, a;
   cin>>n>>d>>a;
   vector<P> mon;
   rep(i, n){
      ll x, h;
      cin>>x>>h;
      mon.push_back(make_pair(x, h));
   }

   sort(mon.begin(), mon.end());
   ll cnt=0;
   ll sdm=0;
   vector<ll> ds(n);
   rep(i, n){
      ll x=mon[i].first, h=mon[i].second;
      ll r=(ll)x+(ll)2*d;
      auto rit=upper_bound(mon.begin(), mon.end(), make_pair(r, LLONG_MAX));
      int ri= rit-mon.begin()-1;
      ll remh= h-sdm;
      if(remh>0){
         ll num= (remh-1)/a+1;
         cnt+=num;
         ll dm=a*num;
         sdm+=dm;
         ds[ri]+= -dm;
      }
      sdm+= ds[i];
   }

   cout<<cnt<<endl;
   return 0;
}
