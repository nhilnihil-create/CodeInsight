#include<bits/stdc++.h>
using namespace std;

int main(){
  long long a, b;
  cin >> a >> b;
  if(a == 1 || b == 1) cout << 1 << endl;
  else cout << (long long)((a * b + 2 - 1) / 2) << endl;
}
