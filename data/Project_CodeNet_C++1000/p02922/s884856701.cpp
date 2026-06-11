#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  int s = a - 1; //増加文
  int t = b - 1;//目標
  int ans = (t+s-1) / s;
  cout << ans << endl;
}