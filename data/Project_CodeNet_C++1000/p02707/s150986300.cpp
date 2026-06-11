#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n-1;i++){
    cin>>a.at(i);
  }
  vector<int> b(n);
  for(int i=0;i<n-1;i++){
    b.at(a.at(i)-1)++;
  }
  for(int i=0;i<n;i++){
    cout<<b.at(i)<<endl;
  }
}