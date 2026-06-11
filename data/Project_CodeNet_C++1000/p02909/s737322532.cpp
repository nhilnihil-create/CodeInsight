#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    string w;
    cin >> w;
    if (w == "Sunny") {
        w = "Cloudy";
    } else if (w == "Cloudy") {
        w = "Rainy";
    } else if (w == "Rainy") {
        w = "Sunny";
    }
    cout << w << endl;
    return 0;
}