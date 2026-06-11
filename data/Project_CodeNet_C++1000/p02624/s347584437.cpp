#include<bits/stdc++.h>
using namespace std;

int main() {
  long long n, s = 0;
  cin >> n;
  for(int i = 1;i <= n;i++) s += n/i*(n/i+1)/2*i;
  cout << s << endl;
}