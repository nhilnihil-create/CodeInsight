#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e5 +7;

#include <math.h>
#define PI 3.14159265358979323846264338327950L



int main() {
    int n;
    cin >> n;
    set<string> mySet;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mySet.insert(s);
    }
    cout << mySet.size();

    return 0;
}