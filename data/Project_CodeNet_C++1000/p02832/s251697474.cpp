#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  int p = 1, count = 0;
  for(int i = 0; i < n; i++){
    if(a[i] == p){
      p++;
      count++;
    }
  }
  cout << (count == 0 ? -1 : n - count) << endl;
}