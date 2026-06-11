#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <climits>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;
using VVI = vector<vector<long long int> >;

void dfs(Int start, vector<pair<Int, Int> >& h, vector<vector<Int> >& table, vector<bool>& check) {
    /*
    cout << "START_DFS" << endl;
    for (Int j = 0; j < check.size(); ++j) {
        cout << check[j] << " ";
    }
    cout << endl;
    */
    for (Int i = 0; i < table[start].size(); ++i) {
        //cout << "POINT = " << start << " " << table[start][i] << endl;
        //cout << "HEIGHT = " << h[start].first << " "  << h[table[start][i]].first << endl;
        if (check[table[start][i]]) {
            //cout << "DFS" << endl;
            if (h[start].first == h[table[start][i]].first) {
                //cout << "IF" << endl;
                check[table[start][i]] = false;
                check[start] = false;
            } else if (h[start].first < h[table[start][i]].first) {
                //cout << "ELSE IF < " << endl;
                check[start] = false;
            } else if (h[start].first > h[table[start][i]].first) {
                //cout << "ELSE IF > " << endl;
                check[table[start][i]] = false;
            }
            dfs(table[start][i], h, table, check);
        }
    }
    //cout << "END_DFS" << endl;
    return;
}

int main(void) {
    Int n, m;
    cin >> n >> m;
    Int a, b;
    vector<pair<Int, Int> > h(n);
    for (Int i = 0; i < n; ++i) {
        h[i].second = i;
        cin >> h[i].first;
    }
    vector<vector<Int> > table(n);
    for (Int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a; --b;
        table[a].push_back(b);
        table[b].push_back(a);
    }
    vector<bool> check(n, true);
    /*
       cout << "TABLE" << endl;
       for (Int i = 0; i < n; ++i) {
       for (Int j = 0; j < table[i].size(); ++j) {
       cout << table[i][j] << " ";
       }
       cout << endl;
       }
     */

    for (Int i = 0; i < n; ++i) {
        //cout << "START" << endl;
        if (check[i] == true) {
            //cout << h[i].second << " " << h[i].first << endl;
            dfs(h[i].second, h, table, check);
        }
        //cout << "END" << endl;
    }
    Int cnt = 0;
    for (Int i = 0; i < check.size(); ++i) {
        if (check[i]) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
