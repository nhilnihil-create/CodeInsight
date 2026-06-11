#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  if (S == "RRR") cout << 3;
  if (S == "SRR") cout << 2;
  if (S == "RSR") cout << 1;
  if (S == "RRS") cout << 2;
  if (S == "SSR") cout << 1;
  if (S == "RSS") cout << 1;
  if (S == "SRS") cout << 1;
  if (S == "SSS") cout << 0;
}
