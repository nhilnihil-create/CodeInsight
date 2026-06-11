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
    vector<int> A(N);
    int sum = 0;
    for(int i = 0; i < N;  i++) {
        cin >> A[i];
        sum += A[i];
    }
    int count = 0;
    for(int i = 0; i < N; i++){
        if(A[i] >= (sum + 4 * M - 1)/ (4 * M)) count++;
    }
    if(count >= M) puts("Yes");
    else puts("No");
}
