#include <bits/stdc++.h>
using namespace std;

int main() { 
  string S;
  cin >> S;
  int C=0;
  if (S=="SUN") {C=7;}
  if (S=="MON") {C=6;}
  if (S=="TUE") {C=5;}
  if (S=="WED") {C=4;}
  if (S=="THU") {C=3;}
  if (S=="FRI") {C=2;}
  if (S=="SAT") {C=1;}
  cout << C << endl;
} 