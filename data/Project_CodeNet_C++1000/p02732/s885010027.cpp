#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define MOD7 1000000007
#define LL_INF 9000000000000000000
#define LL_MINF -9000000000000000000
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

ll nCr(int n, int r){
  ll num = 1;
  for(int i = 1; i <= r; i++){
    num = num * (n - i + 1) / i;
  }
  return num;
}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    map<int,int> M;
    for(int a : A) M[a]++;
    ll ans = 0;
    for(auto p : M){
        ans += nCr(p.se, 2);
    }
    for(int a : A){
        cout << ans - nCr(M[a], 2) + nCr(M[a] -1, 2) << endl;
    }
}