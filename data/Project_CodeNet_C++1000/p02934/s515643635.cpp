#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  double N;cin>>N;
  vector<double> data(N);
  rep(i,N) cin>>data[i];
  double sum =0;
  rep(i,N) sum+=1.0/data[i];
  cout << fixed << setprecision(6);
  cout << 1.0/sum << endl;
}