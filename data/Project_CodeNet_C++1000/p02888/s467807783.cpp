#include<bits/stdc++.h>
using namespace std;

int64_t nibun(vector<int>&l,int j,int num){
  int hidari=j;
  int migi=l.size();
  int64_t tmp=hidari;
  while(migi-hidari>1){
    int mid=(hidari+migi)/2;
    if(l.at(mid)>=num){
      migi=mid;
    }
    else{
      hidari=mid;
    }
    tmp=hidari;
  }
  return tmp;
}

int main(){
  int n;cin>>n;
  vector<int>l(n);
  int64_t ans=0;
  int64_t tmp;
  for(int i=0;i<n;i++){
    cin>>l.at(i);
  }
  sort(l.begin(),l.end());
  for(int i=0;i<n-2;i++){
    for(int j=i+1;j<n-1;j++){
      tmp=nibun(l,j,l.at(i)+l.at(j));
      ans+=tmp-j;
    }
  }
  cout <<ans<<endl;
}