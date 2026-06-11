#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    string s;

    cin >> s;

    if (s == "Sunny") {
        cout << "Cloudy" << endl;
    } else if (s == "Cloudy") {
        cout << "Rainy" << endl;
    } else if (s == "Rainy") {
        cout << "Sunny" << endl;
    }
    return 0;
}