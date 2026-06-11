#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define all(a) (a).begin(), (a).end()


int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for(int i = 0; i < M; i++) cin >> A[i];
    ll day = 0;
    for(int i = 0; i < M; i++) day+=A[i];
    if(N >= day) cout << N - day << endl;
    else puts("-1");
}
