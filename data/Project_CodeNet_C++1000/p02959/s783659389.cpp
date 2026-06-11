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
    vector<ll> A(N+1), B(N);
    for(int i = 0; i < N+1; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    ll sum = 0;
    for(int i = 0; i < N; i++){
        if(B[i] > A[i]){
            sum += A[i] + min(B[i] - A[i], A[i+1]);
            A[i + 1] = max(A[i + 1] - (B[i] - A[i]), ll(0));
        }else sum+= B[i];
    }
    cout << sum << endl;
}