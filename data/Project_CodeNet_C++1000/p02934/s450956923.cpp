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
    for(int i = 0; i < N; i++) cin >> A[i];
    double down = 0;
    for(int i = 0; i < N; i++){
        down += (double)1 / A[i];
    }
    cout << 1 / down << setprecision(15) << endl;
}
