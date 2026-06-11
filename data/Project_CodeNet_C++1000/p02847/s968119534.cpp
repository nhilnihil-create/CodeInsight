#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
    string s;
    cin >> s;
    vector<string> days = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    rep(i, 7) {
        if (s == days[i]) {
            cout << 7 - i << endl;
            return 0;
        } 
    }
    return 0;
}