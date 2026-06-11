#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define all(a) (a).begin(), (a).end()


int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    vector<int> C(N-1);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    for(int i = 0; i < N - 1; i++) cin >> C[i];
    ll sum = 0;
    for(int i = 0; i < N; i++) sum += B[i];

    for(int i = 0; i < N-1; i++){
        if(A[i] + 1 == A[i + 1]){
            sum+=C[A[i]-1];
        }
    }
    cout << sum << endl;
}
