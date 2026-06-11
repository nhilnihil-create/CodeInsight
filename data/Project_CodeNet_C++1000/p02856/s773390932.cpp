#include <bits/stdc++.h>
using namespace std;

int M;

int main() {
  cin >> M;
  long long total_n=0LL;
  long long total_q=0LL;
  for (int i=0;i<M;i++) {
    long long d,c;cin >> d >> c;
    total_n+=c;
    total_q+=c*d;
  }
  cout << total_n-1L+(total_q-1L)/9L << endl;
}