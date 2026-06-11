#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n;
  vector<int>a(n);
  for(int i=0;i<n-1;i++){
    cin >> k;
    a.at(k-1)++;
  }
  for(int i=0;i<n;i++){
    cout << a.at(i) << '\n';
  }
}