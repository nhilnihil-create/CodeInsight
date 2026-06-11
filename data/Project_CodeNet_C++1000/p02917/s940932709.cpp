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

int main(){
    int N;
    cin >> N;
    vector<int> B(N-1);
    for(int i = 0; i < N - 1; i++) cin >> B[i];
    vector<int> A(N);
    A[0] = B[0];
    A.back() = B.back();
    for(int i = 1; i < N - 1; i++){
        A[i] = min(B[i - 1], B[i]);
    }
    int sum = 0;
    for(int a : A) sum+= a;
    cout << sum << endl;
}