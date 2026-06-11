#include <bits/stdc++.h>
using namespace std;

bool kaibun(string s){
  int n=s.size();
  bool kai=true;
  for(int i=0;i<n/2;i++){
    if(s.at(i)!=s.at(n-i-1)){
      kai=false;
    }
  }
  return kai;
}

int main(){
  string S;
  cin>>S;
  int N=S.size();

  bool l1, l2, l3;
  
  l1 = kaibun(S);
  l2 = kaibun(S.substr(0, (N-1)/2));
  l3 = kaibun(S.substr((N+3)/2-1, N));
  
  if(l1&&l2&&l3){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
  
}