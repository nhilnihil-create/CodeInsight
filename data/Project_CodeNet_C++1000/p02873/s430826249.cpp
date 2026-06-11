#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  int N=S.size();
  int64_t Z=0,l=0,r=0;
  for(int i=0;i<N;i++){
    if(S.at(i)=='<'){
      if(r!=0){
        Z+=r*(r+1)/2+l*(l+1)/2-min(l,r);
        l=0,r=0;
      }
      l++;
    }
    else{
      r++;
    }
  }
  Z+=r*(r+1)/2+l*(l+1)/2-min(l,r);
  cout<<Z<<endl;
}


