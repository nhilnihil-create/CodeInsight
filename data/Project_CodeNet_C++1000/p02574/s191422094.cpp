#include<bits/stdc++.h>
using namespace std;
int main(){
int n,k=1000005;
  cin>>n;
  vector<int> a(n);
  vector<int> c(k);
  for(int i=0;i<n;i++){
    cin>>a[i];
    c[a[i]]++;
  }
  bool pairwise=true;
  for(int i=2;i<k;i++){
    int cnt=0;
    for(int j=i;j<k;j+=i){
      cnt+=c[j];
    }
    if(cnt>1) pairwise=false;
  }
  
  if(pairwise){
    cout<<"pairwise coprime"<<endl;
    return 0;
  }
  
  int g=0;
  for(int i=0;i<n;i++) g=gcd(g,a[i]);
  if(g==1){
cout<<"setwise coprime"<<endl;
    return 0;
  }
  cout<<"not coprime"<<endl;
  return 0;
}