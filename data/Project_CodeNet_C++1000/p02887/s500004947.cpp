#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
      
  long long num,fin=0;
  string str;
  char a=str[0];
  cin >> num >> str;
  for (int i=0; i<num; i++) {
      char b=str[i];
      if (a!=b){
          fin++;}
      a=b;}
    cout << fin;}