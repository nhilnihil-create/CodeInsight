#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  set<int> s;
  string ans="YES";
  cin>> n;
  for(int i=0; i<n; i++){
    int a;
    cin>> a;
    if(s.count(a)){
      ans="NO";
      break;
    }
    s.insert(a);
  }
  cout<< ans <<endl;
}