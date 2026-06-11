#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int k,q;
  cin>>k>>q;
  vector<Int> ds(k);
  for(Int i=0;i<k;i++) cin>>ds[i];
  for(Int t=0;t<q;t++){
    Int n,x,m;
    cin>>n>>x>>m;
    n--;

    Int sum=x%m;
    Int ans=n;
    for(Int i=0;i<k;i++){
      sum+=(ds[i]%m)*(n/k+(i<n%k));
      if(ds[i]%m==0){
        ans-=n/k;
        if(i<n%k) ans--;
      }
    }
    ans-=sum/m;
    cout<<ans<<endl;
  }
  return 0;
}
