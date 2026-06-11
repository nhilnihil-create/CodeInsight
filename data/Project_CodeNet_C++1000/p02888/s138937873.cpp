#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  ll i,j,n,l[2010];
  cin >> n;
  for(i=0;i<n;i++){
    cin >> l[i];
  }
  sort(l,l+n);
  ll ans=0;
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      ll x=abs(l[i]-l[j]),min=-1,max=n;
      while(abs(min-max)>1){
        ll mid=(min+max)/2;
        if(l[mid]>x){
          max=mid;
        }
        else{
          min=mid;
        }
      }
      if(max==n){
        continue;
      }
      ll y=max;
      x=l[i]+l[j],min=-1,max=n;
      while(abs(min-max)>1){
        ll mid=(min+max)/2;
        if(l[mid]<x){
          min=mid;
        }
        else{
          max=mid;
        }
      }
      ll z=min,res=0;
      if(z==-1){
        continue;
      }
      if(i>=y && i<=z){
        res++;
      }
      if(j>=y && j<=z){
        res++;
      }
      if(z-y-res+1>0){
        ans+=(z-y-res+1);
      }
    }
  }
  cout << ans/3 << endl;
}