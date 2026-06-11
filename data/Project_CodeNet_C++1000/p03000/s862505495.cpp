#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define all(a) (a).begin(), (a).end()


int main(){
    int N, X;
    cin >> N >> X;
    vector<int> L(N);
    for(int i = 0; i < N; i++) cin >> L[i];
    int count = 1;
    int D = 0;
    for(int i = 0; i < N; i++){
        D = D + L[i];
        if(D <= X) count++;
    }
    cout << count << endl;
}
