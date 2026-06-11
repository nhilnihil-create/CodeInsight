#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define all(a) (a).begin(), (a).end()


int main(){
    ull X;
    cin >> X;
    ull yen = 100;
    ll count = 0;
    while(yen < X){
        yen+=yen/100;
        count++;
    }
    cout << count << endl;
}
