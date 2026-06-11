#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string a, b;
  long long e=0;
  cin >> a >>b;
  for (int i=0; i<3;i++){
    char c=a[i], d=b[i];
    if (c==d){
      e++;}}
  cout << e;}