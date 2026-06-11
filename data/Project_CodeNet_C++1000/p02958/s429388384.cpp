#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,s=0;
  cin >> n;
  vector<int> p(n);
  int i;
  for(i=0;i<n;i++){
    cin >> p.at(i);
    if(p.at(i)==i+1){
      s++;
    }
  }
  
  if(s>=n-2){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}