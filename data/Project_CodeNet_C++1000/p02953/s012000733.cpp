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
    vector<int> H(N);
    for(int i = 0; i < N; i++) cin >> H[i];
    int max_n = 0;
    bool ok = true;
    for(int i = 0; i < N; i++){
        max_n = max(max_n, H[i]-1);
        if(H[i] < max_n) ok = false;
    }
    
    if(ok) puts("Yes");
    else puts("No");
}