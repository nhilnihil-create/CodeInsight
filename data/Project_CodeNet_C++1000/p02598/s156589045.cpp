#include <bits/stdc++.h>
using namespace std;

long long N, K;
vector<long double> A(200001);

bool nibun(int x){
  long long sum = 0;
  for(int i = 0; i < N; i++){
    sum += ceil(A[i] / x) - 1;
  }
  if(sum <= K){
    return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  cin >> N >> K;
  long double maxx = 0;
  for(int i = 0; i < N; i++){
     cin >> A[i];
     maxx = max(maxx, A[i]);
  }
  int l = 0, r = maxx;
  int m;
  while(r - l > 1){
    m = (r + l) / 2;
    //cout << l << " " << r << " " << m <<endl;
    if(nibun(m)){
      //cout << m << " ok" <<endl;
      r = m;
    } else{
      //cout << m << " bad" <<endl;
      l = m;
    }
  }
  cout << r <<endl;
}
