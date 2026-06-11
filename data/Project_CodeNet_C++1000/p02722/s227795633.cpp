#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n;
  cin>>n;
  int c=0;
  vector<int64_t> d;
  for(int64_t i=1;i*i<=n-1;i++){
    if((n-1)%i==0){
      if(i!=1)
        d.push_back(i);
      if(i*i!=n-1)
        d.push_back((n-1)/i);
    }
  }
  sort(d.begin(),d.end());
  for(int64_t k=2,i=0;k*k<=n;k++){
    if(i<d.size()&&k==d.at(i)){
      i++;
      continue;
    }
    int64_t x=n;
    while(x%k==0)
      x/=k;
    c+=(x%k==1?1:0);
  }
  
  cout<<c+d.size()+1<<endl;
}