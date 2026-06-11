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

int init_BIT(std::vector<long long int> &BIT, int N_MAX);
int add_num(std::vector<long long int> &BIT, long long int N_MAX, long long int index, long long int d);
long long int cumulative_sum(std::vector<long long int> &BIT, long long int r);


int main(){

  // read problem
  ll N, tmp;
  cin >> N;
  vector<ll> P(N), P_inv(N);
  
  for(ll i = 0; i < N; i++){
    cin >> tmp;
    P[i] = tmp-1;
    P_inv[tmp-1] = i;
  }

  // prepare BIT  
  long long int N_MAX = 1<<18; 
  std::vector<long long int> BIT(N_MAX);
  
  // solve problem
  ll L1, L2, R1, R2, l, r, mid, sumtmp;
  ll ans = 0;

  for(ll i = N-1; i >= 0; i--){
    //cerr << "i = " << i << endl;

    // update count
    add_num(BIT, N_MAX, P_inv[i], 1);
    sumtmp = cumulative_sum(BIT, P_inv[i]);

    // determine L2
    if(sumtmp == 1){
      L2 = -1;
    }
    else{
      r = P_inv[i]-1;
      l = -1;
      while(r-l > 1){
        mid = (r+l)/2;
        if(cumulative_sum(BIT, mid) == sumtmp-1){
          r = mid;
        }
        else{
          l = mid;
        }
      }
      L2 = r;
    }

    // determine L1
    if(sumtmp <= 2){
      L1 = -1;
    }
    else{
      r = L2-1;
      l = -1;
      while(r-l > 1){
        mid = (r+l)/2;
        if(cumulative_sum(BIT, mid) == sumtmp-2){
          r = mid;
        }
        else{
          l = mid;
        }
      }
      L1 = r;
    }

    // determine R1
    if(N-i - sumtmp == 0){
      R1 = N;
    }
    else{
      r = N-1;
      l = P_inv[i];
      while(r-l > 1){
        mid = (r+l)/2;
        if(cumulative_sum(BIT, mid) == sumtmp){
          l = mid;
        }
        else{
          r = mid;
        }
      }
      R1 = r;
    }
    // determine R2
    if(N-i - sumtmp <= 1){
      R2 = N;
    }
    else{
      r = N-1;
      l = R1;
      while(r-l > 1){
        mid = (r+l)/2;
        if(cumulative_sum(BIT, mid) == sumtmp+1){
          l = mid;
        }
        else{
          r = mid;
        }
      }
      R2 = r;
    }

    //cerr << L1 << " " << L2 << " " << R1 << " " << R2 << " " << endl;
    // update answer
    ans += (i+1)*((P_inv[i]-L2) * (R2-R1) + (L2-L1)*(R1-P_inv[i]));
    //cerr << ans << endl;
  }

  cerr << "Answer: " << endl;
  cout << ans << endl;

  return 0;
}


int add_num(std::vector<long long int> &BIT, long long int N_MAX, long long int index, long long int d){
  index ++;
  while(index < N_MAX){
    BIT[index-1] += d;
    index += (index & -index);
  }
  
  return 0;
}

long long int cumulative_sum(std::vector<long long int> &BIT, long long int r){
  // sum of no elements
  if(r == -1){
    return 0;
  }
  
  r++;
  long long int sum = 0;
  while(r > 0){
    sum += BIT[r-1];
    r -= (r & -r);
  }
  
  return sum;
}

