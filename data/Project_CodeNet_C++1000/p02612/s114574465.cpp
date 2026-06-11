#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int x = n%1000;
  if(x!=0)
	cout << 1000 - n%1000 << endl;
  else
    cout << 0 << endl;
}
