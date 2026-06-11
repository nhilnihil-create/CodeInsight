#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,b,x=0,zero=0;
  cin >> n;
  bool ans=true,ok=true;
  map<int,int>f;
  for(int i=0;i<n;i++){
    cin >> b;
    f[b]++;
    x^=b;
    if(b==0)
      zero++;
  }
  if(zero!=n&&!(n%3==0&&n/3==zero)){
  for(auto x:f){
    if(x.second!=n/3)
      ok=false;
  }
  }
  ans=(x==0);
  cout << (ans&&ok?"Yes":"No") << endl;
  return 0;
}