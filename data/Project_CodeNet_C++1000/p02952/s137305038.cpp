#include <iostream>
#include <algorithm>

using namespace std;

string st;

int const nmax = 50;
int barby[1 + nmax];

int main() {

  long long n, bees, ans = 0, ogn;
  long long popo = 1;
  cin >> n;
  ogn = n;
  ans = 0;
  bees = 0;
  while(n > 0){
    bees++;
    if(bees % 2 == 1){
      if(ogn >= popo * 10){
        ans += popo * 9;
      }else{
        ans += ogn - popo + 1;
      }
    }
    n /= 10;
    popo *= 10;
  }
  cout << ans;
  return 0;
}
