#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> as(n);
  for(Int i=0;i<n;i++) cin>>as[i];

  Int sum=0;
  for(Int a:as) sum^=a;
  for(Int &a:as) a&=~sum;

  Int res=0;
  const Int MAX = 60;
  for(Int j=MAX,k=0;j>=0;j--){
    for(Int i=k+1;i<n;i++)
      if((as[i]>>j)&1) swap(as[k],as[i]);

    if((~as[k]>>j)&1) continue;

    for(Int i=k+1;i<n;i++)
      if((as[i]>>j)&1) as[i]^=as[k];

    if((~res>>j)&1) res^=as[k];
    k++;
  }

  cout<<res+(sum^res)<<endl;
  return 0;
}
