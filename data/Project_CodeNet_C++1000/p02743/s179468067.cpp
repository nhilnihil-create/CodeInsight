#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i, a, b) for(long long i = a; i < b; i++)
#define ll long long
using namespace std;

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  if(c-a-b > 0 && 4*a*b < (c-a-b)*(c-a-b)) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}