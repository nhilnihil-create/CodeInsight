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
    vector<int> D(N);
    for(int i = 0; i < N; i++) cin >> D[i];
    ll sum = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            sum+=D[i]*D[j];
        }
    }
    cout << sum / 2 << endl;
}
