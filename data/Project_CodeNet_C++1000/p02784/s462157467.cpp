#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define all(a) (a).begin(), (a).end()


int main(){
    int H, N;
    cin >> H >> N;
    vector<int>A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    ll total = 0;
    for(int a : A) total+=a;
    if(total >= H) puts("Yes");
    else puts("No");
}
