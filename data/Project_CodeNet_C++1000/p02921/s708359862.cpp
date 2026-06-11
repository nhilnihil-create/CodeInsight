#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()


int main(){
    string S, T;
    cin >> S >> T;
    int count = 0;
    for(int i = 0; i < 3; i++) if(S[i] == T[i]) count++;
    cout << count << endl;
}
