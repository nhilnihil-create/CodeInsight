#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k;
  cin>>n>>k;
  vector<int>a(n);
  int b=0;
  for(int i=0;i<n;i++){
    cin>>a.at(i);
    if(a.at(i)>=k){
      b++;
    }
  }
  cout<<b;
}