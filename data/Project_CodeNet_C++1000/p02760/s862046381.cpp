#include <bits/stdc++.h>
 
#define DEBUG(x)        do { std::cerr << #x << " = " << x << std::endl;  } while(0)
#define DEBUGV(x)       for(auto e : x) { std::cerr << e << " "; }; cout << endl;
#define INFO(msg)       do { std::cerr << msg << std::endl; } while(0)
#define ll              long long
#define vi              vector<int>
#define pii             pair<int, int>
#define fori(i, s, e)   for(int i = s; i < e; i++)
#define ford(i, s, e)   for(int i = s; i >= e; i--)
 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<int, pii> m;
    int x;

    fori(i, 0, 3) {
        fori(j, 0, 3) {
            cin >> x;
            m[x] = make_pair(i, j);
        }
    }

    int n, s = 0;
    cin >> n;

    int rows[3], cols[3], diags[2];
    memset(rows, 0, sizeof rows);
    memset(cols, 0, sizeof cols);
    memset(diags, 0, sizeof diags);

    fori(i, 0, n) {
        cin >> x;
        if(m.find(x) == m.end()) continue;
        rows[m[x].first]++;
        cols[m[x].second]++;
        if(m[x].first == m[x].second) diags[0]++;
        if(m[x].first == 2 - m[x].second) diags[1]++;
        if(rows[m[x].first] == 3 || cols[m[x].second] == 3 || diags[0] == 3 || diags[1] == 3) {
            cout << "Yes" << endl;
            s = 1;
            break;
        }
    }

    if(!s) {
        cout << "No" << endl;
    }

    return 0;
}
