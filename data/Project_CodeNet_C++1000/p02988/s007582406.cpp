#include <bits/stdc++.h>
using namespace std;
int main() { 
  int n;
  cin>>n;
  vector<int>a(n);
  int b=0;
  for(int i=0;i<n;i++){
    cin>>a.at(i);
    if(i>=2){
    if(a.at(i-2)<a.at(i-1)&&a.at(i-1)<a.at(i)||
       a.at(i-2)>a.at(i-1)&&a.at(i-1)>a.at(i)){
    b++;
    }
    }
  }
  cout<<b;
}