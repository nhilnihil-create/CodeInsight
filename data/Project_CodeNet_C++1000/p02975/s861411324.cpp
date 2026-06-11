#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,i,j;
  cin >> n;
  vector<ll> a(n),p(31);
  for(i=0;i<n;i++){
    cin >> a.at(i);
  }
  
  sort(a.begin(),a.end());
  if(n%3!=0){
    if(a.at(n-1)!=0){
      cout << "No" << endl;
    }else{
      cout << "Yes" << endl;
    }
    return 0;
  }
  
  for(i=0;i<n-1;i++){
    if(i!=n/3-1&&i!=n*2/3-1&&a.at(i)!=a.at(i+1)){
      cout << "No" << endl;
      return 0;
    }
  }
  
  int x,y,z,Z;
  x=a.at(0);
  y=a.at(n/3);
  z=a.at(n*2/3);
  Z=0;
  
  p.at(0)=1;
  for(j=1;j<31;j++){
    p.at(j)=p.at(j-1)*2;
  }
  
  vector<int> bitx(31,0),bity(31,0);
  for(j=0;j<31;j++){
    bitx.at(j)=x%2;
    x /= 2;
    bity.at(j)=y%2;
    y /= 2;
    Z += p.at(j)*((bitx.at(j)+bity.at(j))%2);
  }
  
  if(Z==z){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}