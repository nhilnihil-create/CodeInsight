#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    string s; cin >> s;

    int n = s.size();
    for(int i = 0; i < n; i++){
        if(i % 2 == 0 && (s[i] == 'R' || s[i] == 'U' || s[i] == 'D')) continue;
        if(i % 2 != 0 && (s[i] == 'L' || s[i] == 'U' || s[i] == 'D')) continue;
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}
