#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
typedef int64_t ll;

int main(){
  ll n,q;
  cin>>n>>q;
  atcoder::fenwick_tree<ll> fw(n);
  for(int i=0;i<n;i++){
    ll a;
    cin>>a;
    fw.add(i,a);
  }
  for(int i=0;i<q;i++){
    ll t,x,y;
    cin>>t>>x>>y;
    if(t==0){
      fw.add(x,y);
    }
    else{
      cout<<fw.sum(x,y)<<endl;
    }
  }
}
