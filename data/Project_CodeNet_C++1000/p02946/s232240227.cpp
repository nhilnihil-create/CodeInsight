#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define all(a) (a).begin(), (a).end()


int main(){
    int K, X;
    cin >> K >> X;
    int start = X - K + 1;
    int end = X + K - 1;
    for(int i = start; i <= end; i++)cout << i << ' ';
    cout << endl;
}
