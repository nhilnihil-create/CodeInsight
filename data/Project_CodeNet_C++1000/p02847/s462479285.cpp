#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    vector<string> day{"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    cin >> s;
    for(int i = 0; i < 7; i++) {
        if (day.at(i) == s) cout << 7-i << endl; 
    }
    return 0;
}