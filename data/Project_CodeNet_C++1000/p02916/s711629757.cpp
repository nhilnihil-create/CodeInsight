#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
  }
  vector<int>b(n);
  int d=0;
  for(int i=0;i<n;i++){
    cin>>b.at(i);
    d+=b.at(i);
  }
  vector<int>c(n-1);
  for(int k=0;k<n-1;k++){
    cin>>c.at(k);
  }
  for(int j=1;j<n;j++){
    if(a.at(j)==a.at(j-1)+1){
      d+=c.at(a.at(j-1)-1);
    }
  }
  cout<<d;
}