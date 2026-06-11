#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, count=0; cin >> n;
  for(int i=0;i<=n;i++){
    if(i>0 && to_string(i).size()%2 != 0) count++;
  }
  cout << count << endl;
  return 0;
}