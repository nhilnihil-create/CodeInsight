#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll n,p;
  cin >> n;
  p=1000000007;
  vector<int> x(n);
  vector<int> a(n);
  int i;
  for(i=0;i<n;i++){
    cin >> a.at(i);
  }
  
  if(a.at(0)!=0){
    cout << 0 << endl;
    return 0;
  }
  
  ll s=1;
  for(i=0;i<n;i++){
    if(x.at(a.at(i))>=3){
      s=0;
    }
    if(a.at(i)==0){
      s=(s*(3-x.at(0)))%p;
    }else{
      if(x.at(a.at(i)-1)<x.at(a.at(i))){
        s=0;
      }else{
        s=(s*(x.at(a.at(i)-1)-x.at(a.at(i))))%p;
      }
    }
    x.at(a.at(i))++;
  }
  
  cout << s << endl;
}