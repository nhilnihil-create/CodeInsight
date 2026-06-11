#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    int N;
    cin >> N;
    string s, t;
    cin >> s >> t;

    rep(i, N) { cout << s[i] << t[i]; }
    cout << endl;
}
