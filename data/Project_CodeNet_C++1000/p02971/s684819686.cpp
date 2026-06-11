#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int>a(n);
  int b=0;
  for(int i=0;i<n;i++){
    cin>>a.at(i);
    b=max(b,a.at(i));
  }
  int c=0;
  int d=0;
  for(int i=0;i<n;i++){
    if(a.at(i)==b){
      c++;
    }
    else{
      d=max(d,a.at(i));
    }
  }
  for(int i=0;i<n;i++){
    if(c!=1){
      cout<<b<<endl;
    }
    else if(c==1&&a.at(i)==b){
      cout<<d<<endl;
    }
    else if(c==1&&a.at(i)!=b){
      cout<<b<<endl;
    }
  }
}