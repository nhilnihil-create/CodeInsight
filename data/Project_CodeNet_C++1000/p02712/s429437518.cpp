#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

int main() {
  int N;
  cin >> N;
  long long sum = 0;
  long long minus = 0;
  rep(i, N) {
    long long tmp = i + 1;
    sum += tmp;
    if((tmp%3) == 0 && (tmp%5) != 0) minus += tmp;
    else if((tmp%5) == 0 && (tmp%3) != 0) minus += tmp;
    else if((tmp%3) == 0 && (tmp%5) == 0) minus += tmp;
  
  }
  cout << (sum - minus) << endl;
}