#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll A;
  double B;
  cin >> A >> B;
  ll ib = B * 100 + 0.5;
  A *= ib;
  A /= 100;
  cout << A << endl;
}