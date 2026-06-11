#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
 int X, Y, Z, x, H;
 cin >> X;
 Y = X / 500;
 x = X % 500;
 Z = x / 5;
 H = Y * 1000 + Z * 5;
 cout << H << endl;
}