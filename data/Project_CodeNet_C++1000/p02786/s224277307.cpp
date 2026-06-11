#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
  ll n;
  cin >> n;
  int k = log(n) / log(2);
  cout << (ll)pow(2, k + 1) - 1 << endl;
}