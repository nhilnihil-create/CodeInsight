#include<bits/stdc++.h>
using namespace std;
int main(void) {
  long long int n, m;
  cin >> n >> m;
  long long int prod = n * m;
  long long ans = prod / 2;
  if(prod & 1) {
    ans++;
  }
  if(n == 1 || m == 1) {
    cout<<"1\n";
  } else {
  	cout << ans << "\n";
  }
}