#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,l;
  cin>>n>>l;
  int wa=0;
  bool zero=false;
  int saishou=INT_MAX;
  int saidai=-1*INT_MAX;
  for(int i=l;i<l+n;i++){
    if(i==0)zero=true;
    if(i<0)saidai=max(saidai,i);
    if(i>0)saishou=min(saishou,i);
    wa+=i;
  }
  if(zero==true){
    cout<<wa<<endl;
    return 0;
  }
  if (l+n-1<0)cout<<wa-saidai<<endl;
  else cout<<wa-saishou<<endl;
  return 0;
}