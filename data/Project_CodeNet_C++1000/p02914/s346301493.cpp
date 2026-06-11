#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <climits>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;

ll maxSubarrayXOR(ll set[], ll n){
  ll index = 0;
  for (int i = 63; i >= 0; i--){
    ll maxInd = index;
    ll maxEle = LLONG_MIN;
    for (int j=index;j<n;j++) if(((set[j]&(1<<i))!=0) && set[j]>maxEle) maxEle=set[j],maxInd = j;
    if (maxEle==LLONG_MIN) continue;
    swap(set[index], set[maxInd]);
    maxInd = index;
    for (int j=0; j<n; j++) if (j!=maxInd&&((set[j]&(1<<i))!=0))set[j]^=set[maxInd];
    index++;
  }
  ll res = 0;
  for (int i = 0; i < n; i++) res ^= set[i];
  return res;
}
int main(int argc, char const *argv[]) {
  ll N;
  std::cin >> N;
  ll A[N];
  ll d = 0, b = 0;
  for(int i=0;i<N;i++){
    std::cin >> A[i];
    d ^= A[i];
  }
  for(int i=0;i<N;i++) A[i] &= ~d;

  b = maxSubarrayXOR(A, N);
  ull rank = 0;
  ll i = 0, j = 0;
	for (i = 59; i >= 0; i--) {
		for (j = rank; j < N; j++) {
			if (A[j] & (1LL << i)) break;
		}
		if (j == N) {
			continue;
		}

		if (j > rank) A[rank] ^= A[j];
		for (j = rank + 1; j < N; j++) {
			A[j] = min(A[j], A[j] ^ A[rank]);
		}

		rank++;
	}
	ull x = 0;
	for (i = 0; i < N; i++) {
		x = max(x, x ^ A[i]);
	}
  //std::cout << d << " " << b << " " << x<< '\n';
  std::cout << d + (x * 2)  << '\n';
  return 0;
}
