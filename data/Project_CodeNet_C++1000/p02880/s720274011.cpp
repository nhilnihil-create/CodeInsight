#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
  vector<int>ans(101,0);
  for(int i = 0;i<10;i++){
    for(int j = 0;j<10;j++){
      ans.at(i*j)= 1;
    }
  }
  int a;
  cin >> a;
  if(ans.at(a))cout << "Yes";
  else cout << "No";
}