#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <complex>

using ll = long long int;
using namespace std;

int main(){

  ll N, M, V, P, tmp;
  vector<ll> A;

  cin >> N >> M >> V >> P;
  for(ll i = 0; i < N; i++){
    cin >> tmp;
    A.push_back(tmp);
  }

  sort(A.begin(), A.end(), greater<ll>());

  cerr << "A:";
  for(ll i = 0; i < N; i++){
    cerr << A[i] << " ";
  }cerr << endl;

  vector<ll> A_accum(N);
  A_accum[0] = A[0];
  for(ll i = 1; i < N; i++){
    A_accum[i] = A_accum[i-1] + A[i];
  }

  ll minscore = 1e10; 
  ll sum_max;
  for(ll prob = 0; prob < N; prob++){
    if(prob < P){
      minscore = A[prob];
      continue;
    }

    if(A[P-1] > A[prob]+M){
      break;
    }

    sum_max = N*M - A_accum[prob] + A_accum[P-2] + A[prob]*(prob+2-P);
    if(sum_max >= V*M){
      minscore = A[prob];
    }
    else{
      break;
    }
  }

  ll ans = 0;
  for(ll i = 0; i < N; i++){
    if(A[i] >= minscore){
      ans++;
    }
  }

  cerr << "Answer:" << endl;
  cout << ans << endl;

  return 0;
}
