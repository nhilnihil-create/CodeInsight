#include <bits/stdc++.h>
using namespace std;
using pp=pair<double,double>;
using ll=long long;

int main() {
  int N;
  cin >> N;
  vector<pp> V(N);
  vector<int> P(N);
  for (int i=0; i<N; i++) {
    cin >> V[i].first >> V[i].second;
    P[i]=i;
  }
  
  double S=0;
  int m=0; 
  do {
    for (int i=0; i<N-1; i++) {
      double x=V[P[i]].first-V[P[i+1]].first, y=V[P[i]].second-V[P[i+1]].second;
      S+=sqrt(x*x+y*y);
    }
    m++;
  } while(next_permutation(P.begin(), P.end()));
  cout << fixed << setprecision(15) << S/m << endl;
}