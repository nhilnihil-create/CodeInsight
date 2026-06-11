#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
  int x;
  cin >> x;
  
  int y = x / 500;
  int z = (x - 500 * y) / 5;
  
  cout << 1000 * y + 5 * z << endl;
  
} 