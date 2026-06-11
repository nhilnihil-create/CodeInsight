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
    int N, K, Q; 
    cin >> N >> K >> Q;
    vector<int> A(Q);
    for(int i = 0; i < Q; i++) cin >> A[i];
    vector<int> point(N, K - Q);
    for(int a : A) point[a - 1]++;
    for(int p : point){
        if(p <= 0) puts("No");
        else puts("Yes");
    }

}