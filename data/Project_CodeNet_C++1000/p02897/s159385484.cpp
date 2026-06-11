#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  double N;
  cin >> N;
  cout << std::fixed << std::setprecision(10);
  if(N==1) cout <<  1.0 << endl;
  else if(int(N)%2==0) cout<<0.5<<endl;
  else cout << ((N+1)/(2*N))<<endl;
}
