#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define all(a) (a).begin(), (a).end()


int main(){
    int N, K;
    cin >> N >> K;
    vector<int> H(N);
    for(int i = 0; i < N; i++) cin >> H[i];
    int count = 0;
    for(int h : H){
        if(h >= K) count++;
    }
    cout << count << endl;
}
