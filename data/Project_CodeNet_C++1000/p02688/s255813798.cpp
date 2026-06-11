#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
  int a,b,c,d;
  cin >> a >> b;
  vector<int> ans(a,0);
  int sum;
  for(int i= 0;i<b;i++){
    cin >> c;
    for(int j = 0;j<c;j++){
      cin >> d;
      ans.at(d-1)++;
    }
  }
  for(int i = 0;i<a;i++){
    if(ans.at(i)==0)sum++;
  }
  cout << sum;
}
