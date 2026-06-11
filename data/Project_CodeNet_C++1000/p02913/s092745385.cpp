//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <time.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
 
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1ll << 60;
const double PI = 2 * asin(1);

int N, A[5005], ans;
string S, now;

int Z_Algorithm(){
  int L = now.length();
  A[0] = L;
  int i = 1, j = 0;
  while (i < L){
    while (i + j < L && now[j] == now[i + j]) j++;
    A[i] = j;
    if (j == 0){i++; continue;}
    
    int k = 1;
    while (i + k < L && k + A[k] < j){
      A[i + k] = A[k]; k++;
    }
    i += k; j -= k;
  }

  for (int i = 0; i < L; i++){
    ans = max(ans, min(i, A[i]));
  }
  
  return 0;
}

int main(){
  cin >> N >> S;
  for (int i = 0; i < N; i++){
    now = S.substr(i, N);
    Z_Algorithm();
  }
  
  cout << ans << endl;
  
  return 0;
}
