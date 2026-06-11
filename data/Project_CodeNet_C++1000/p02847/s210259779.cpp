#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<math.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;
using ll = long long int;

int main(void) {
    string s; cin >> s;
    if (s == "SUN") cout << 7 << endl;
    else if (s == "MON") cout << 6 << endl;
    else if (s == "TUE") cout << 5 << endl;
    else if (s == "WED") cout << 4 << endl;
    else if (s == "THU") cout << 3 << endl;
    else if (s == "FRI") cout << 2 << endl;
    else cout << 1 << endl;
}