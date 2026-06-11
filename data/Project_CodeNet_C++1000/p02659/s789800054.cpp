#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double eps = 1e-6;
 
int main(){
  ll a;
  double b;
  cin >> a >> b;
  ll c = b * 100 + eps;
  cout << ll (a * c) / 100 << endl;
}