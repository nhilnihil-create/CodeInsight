#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long num,b,fin=0;
    cin >> num;
    for (long long i=1; i<=num; i++){
      string a = to_string(i);
      b = a.length();
      if (b%2!=0) {
        fin++;}}
    cout << fin;}