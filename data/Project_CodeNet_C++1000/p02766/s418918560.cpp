#include <iostream>
#include <algorithm>

using namespace std;

string st;

int const nmax = 50;
int barby[1 + nmax];

int main() {

  long long n, bees, ans = 0;
  cin >> n >> bees;
  ans = 1;
  for(long long i = 1;i <= n;i *= bees){
    ans++;
  }
  cout << ans - 1;
  return 0;
}
