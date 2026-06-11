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
    vector<int> W(N);
    for(int i = 0; i < N; i++) cin >> W[i];
    int right = 0;
    for(int i = 0; i < N; i++) right += W[i];
    int dist = 1000000;
    int left = 0;
    for(int i = 0; i < N; i++){
        left += W[i];
        right -= W[i];
        dist = min(dist, abs(left-right));
    }
    cout << dist << endl;
}
