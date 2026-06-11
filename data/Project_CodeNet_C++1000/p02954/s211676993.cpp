#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  string s;
  cin >> s;
  int n=s.size();
  
  vector<int> a(n,0);
  int i,c=0;
  for(i=0;i<n;i++){
    if(s.at(i)=='R'){
      c++;
    }else{
      a.at(i) += c/2;
      a.at(i-1) += (c+1)/2;
      c=0;
    }
  }
  
  c=0;
  for(i=n-1;i>=0;i--){
    if(s.at(i)=='L'){
      c++;
    }else{
      a.at(i) += c/2;
      a.at(i+1) += (c+1)/2;
      c=0;
    }
  }
  
  for(i=0;i<n;i++){
    cout << a.at(i) << " ";
  }
}