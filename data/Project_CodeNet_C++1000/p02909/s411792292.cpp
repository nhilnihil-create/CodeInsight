#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    string s;
    cin >> s;

    if (s == "Sunny") cout << "Cloudy" << endl;
    else if (s == "Cloudy") cout << "Rainy" << endl;
    else if (s == "Rainy") cout << "Sunny" << endl;
    return 0;
}
