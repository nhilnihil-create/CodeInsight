#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string b;
  cin >> n;
  map<string,int>a;
  for(int i=0;i<n;i++){
    cin >> b;
    a[b]++;
  }
  int m=0;
  for(auto x:a)
    m=max(m,x.second);
  for(auto x:a){
    if(x.second==m)
      cout << x.first << endl;
  }
  return 0;
}