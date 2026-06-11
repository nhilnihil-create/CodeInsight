#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  if (n % 2 == 0) cout << double(0.5) << endl;
  else{
    int m = n / 2 + 1;
    cout << double(m) / double(n) << endl;
  }
}
