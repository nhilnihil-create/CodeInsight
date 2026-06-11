#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
 int X,Y,Z,N;
 cin >> X;
 cin >> Y;
 cin >> Z;
 N = X;
 X = Y;
 Y = N;
 N = X;
 X = Z;
 Z = N;
 cout << X << endl;
 cout << Y << endl;
 cout << Z << endl;
}