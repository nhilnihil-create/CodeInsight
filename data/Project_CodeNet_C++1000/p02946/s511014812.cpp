#include <bits/stdc++.h>
using namespace std;

int main() {
  int k,x;
  cin >> k >> x;
  for(int i = x - k + 1 ;i < k + x;i++){
    cout << i;
    if(i == k + x - 1)cout << endl;
    else cout << " ";
  }
}
