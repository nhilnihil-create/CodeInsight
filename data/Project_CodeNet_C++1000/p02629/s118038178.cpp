#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

void printString(ull n) 
{ 
  string res = "";
  while (n) {
    n--;
    res += 'a' + n % 26;
    n /= 26;
  }
  reverse(res.begin(), res.end());
  cout << res;
  cout << endl;
} 

int main() {
  ull n;
  cin >> n;
  printString(n);
}