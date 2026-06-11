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
    for(int i = 0; i < N;i++) cin >> A[i];
    int max_n = 0;
    int max_n2 = 0;
    vector<int> B = A;
    sort(all(B));
    max_n = B.back();
    max_n2 = B[B.size() - 2];
    if(max_n == max_n2) for(int i = 0; i < N; i++) cout << max_n << endl;
    else{
        for(int i = 0; i < N; i++){
            if(A[i] == max_n) cout << max_n2 << endl;
            else cout << max_n << endl;
        }
    }
}