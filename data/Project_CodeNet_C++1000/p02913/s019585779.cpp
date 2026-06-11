#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> Z;
void z_algorithm(string str){//計算量はO(str.size())
  Z.resize(str.size());
  Z.at(0)=str.size();
  int m=1,n=0;
  while(m<(int)str.size()){
    while(m+n<(int)str.size()&&str.at(n)==str.at(m+n)){n++;}
    Z.at(m)=n;
    if(n==0){
      m++;
      continue;
    }
    int k=1;
    while(k+Z.at(k)<n){
      Z.at(m+k)=Z.at(k);
      k++;
    }
    m+=k;
    n-=k;
  }
}
int main(){
  int N,ans=0;
  string S;
  cin>>N>>S;
  for(int i=0;i<N-1;i++){
    z_algorithm(S);
    for(int j=i+1;j<N;j++){
      if(Z.at(j-i)<=(N-i)/2 && Z.at(j-i)<=j-i){ans=max(ans,Z.at(j-i));}
    }
    S.erase(S.begin());
  }
  cout<<ans<<endl;
}