#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()


int main(){
    string s;
    cin >> s;
    map<string, int> A;
    A["SUN"] = 7;
    A["MON"] = 6;
    A["TUE"] = 5;
    A["WED"] = 4;
    A["THU"] = 3;
    A["FRI"] = 2;
    A["SAT"] = 1;
    cout << A[s] << endl;
}
