// Problem F

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <cassert>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <queue>
#include <stack>

#define MAXN 1000
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

ll N;

int main() {
  cin >> N;
  ll n;
  int res = 1; // N va sempre bene
  if (N>2) res++; // also N-1 is fine
  
  for (ll i=2; i<=min((ll)ceil(sqrt(N*1.0)), N-1); i++) {
    if (N%i == 0) {
      n = N;
      do 
	n = n/i ;
      while (n%i == (ll)0);
      if (n%i == (ll)1) {
	res++;
	//~ cout << i << " ";
      }
      
      if (i != N/i && (N % (N/i) == (ll)1)) {
	res++;
	//~ cout << N/i << " ";
      }
    }
  }
  N = N-1;
  for (ll i=2; i<=min(N-1, (ll)ceil(sqrt(1.0*N))); i++) 
    if (N%i==0) {
      //~ cout << i << " ";
      if (i == N/i) res++;
      else res += 2;
    }
      
  cout << res << endl;
  
  return 0;
}
