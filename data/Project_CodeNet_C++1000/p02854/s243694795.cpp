#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int64_t>kil(n);
  int64_t s=0,a=0,k=0,b=0;
  for(int i=0;i<n;i++){
    cin >> kil.at(i);
    s+=kil.at(i);
  }
  while(a<s/2){
    a+=kil.at(k);
    k++;
  }
  if(abs(a-s/2)>abs(a-kil.at(k-1)-s/2)){
    a-=kil.at(k-1);
    k--;
  }
  while(k<kil.size()){
    b+=kil.at(k);
    k++;
  }
  cout << abs(a-b) << endl;
  return 0;
}