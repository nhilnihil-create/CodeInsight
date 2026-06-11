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
    int count = 0;
    for(int i = 1; i <= N; i++) if(to_string(i).size() % 2) count++;
    cout << count << endl;
}
