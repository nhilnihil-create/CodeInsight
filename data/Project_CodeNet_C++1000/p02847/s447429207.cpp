#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    string day;
    cin >> day;
    int n = 0;
    if (day == "SUN") {
        n = 7;
    } else if (day == "MON") {
        n = 6;
    } else if (day == "TUE") {
        n = 5;
    } else if (day == "WED") {
        n = 4;
    } else if (day == "THU") {
        n = 3;
    } else if (day == "FRI") {
        n = 2;
    } else if (day == "SAT") {
        n = 1;
    }
    cout << n << endl;
    return 0;
}