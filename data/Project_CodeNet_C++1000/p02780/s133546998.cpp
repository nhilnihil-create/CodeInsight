#include <bits/stdc++.h>
using namespace std;
int main(){
  int K, N;
  cin >> N >> K;
  vector<double> p(N);
  for(int i=0;i<N;i++) cin >> p.at(i);
  vector<double> E(N);
  for(int i=0;i<N;i++){
    E.at(i) = 1.0/2.0 * (p.at(i) + 1.0);
    //cout << E.at(i) << endl;
  }
  double ma = 0;
  double E_sum = 0;
  for(int i=0;i<K;i++){
      E_sum += E.at(i);
      //cout << E_sum << endl;
    }
  //cout << E_sum << endl;
  ma = max(ma, E_sum);
  for(int i=0;i<N-K;i++){
    E_sum += E.at(K + i);
    E_sum -= E.at(i);
    //cout << E_sum << endl;
    ma = max(ma, E_sum);
  }
  printf("%.10lf\n",ma);
}