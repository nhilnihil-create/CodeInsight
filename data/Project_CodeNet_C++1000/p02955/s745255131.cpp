#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,k,i,j,l,h,s=0;
  vector<int> d;
  cin>>n>>k;
  vector<int> a(n);
  for(i=0;i<n;i++){
    cin>>a.at(i);
    s+=a.at(i);
  }
  for(i=1;i*i<=s;i++){
    if(s%i==0){
      d.push_back(i);
      if(i*i<s) d.push_back(s/i);
    }
  }
  sort(d.begin(),d.end());
  reverse(d.begin(),d.end());
  for(i=0;i<d.size();i++){
    int pl=0,mn=0;
    multiset<int> pls,mns;
    for(j=0;j<n;j++){
      if(a.at(j)%d.at(i)<d.at(i)/2){
        mn+=a.at(j)%d.at(i);
        mns.insert(a.at(j)%d.at(i));
      }
      else{
        pl+=d.at(i)-a.at(j)%d.at(i);
        pls.insert(a.at(j)%d.at(i));
      }
    }
    if(pl>mn){
      auto it=pls.begin();
      h=(pl-mn)/d.at(i);
      for(j=0;j<h;j++){
        l=*next(it,j);
        mn+=l;
        pl-=d.at(i)-l;
      }
    }
    else if(pl<mn){
      auto it=mns.end();
      h=(mn-pl)/d.at(i);
      for(j=0;j<h;j++){
        l=*prev(it,j+1);
        mn-=l;
        pl+=d.at(i)-l;
      }
    }
    if(pl<=k){
      cout<<d.at(i)<<endl;
      break;
    }
  }
}