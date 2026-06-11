#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main() {
    string s;
    cin >> s;
    string wether[3] = {"Sunny", "Cloudy", "Rainy"};

    if(s == wether[0]) {
        cout << wether[1] << endl;
        return 0;
    }
    if(s == wether[1]) {
        cout << wether[2] << endl;
        return 0;
    }
    if(s == wether[2]) {
        cout << wether[0] << endl;
        return 0;
    }
}