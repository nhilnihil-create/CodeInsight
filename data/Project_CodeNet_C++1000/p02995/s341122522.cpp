#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;

int gcd(int a, int b) {
  if (a % b == 0) {
    return (b);
  } else {
    return (gcd(b, a % b));
  }
}

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main() { 
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    ll g = lcm(C, D);
    ll cnt_B = B / C + B / D - B / g;
    ll cnt_A = (A-1) / C + (A-1) / D - (A-1) / g;
    cout << B-A+1-cnt_B + cnt_A << endl;
    return 0;
}