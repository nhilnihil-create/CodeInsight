#include <iostream>
#include <string>
#include <set>
using namespace std;

int n, m, k;
string a[8];
int r[8], c[8], black, ans;

int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < n ; i++) {
        cin >> a[i];
        for(int j = 0; j < m; j++)
            if(a[i][j] == '#')
                black++;
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            r[i] += (a[i][j] == '#');
    for(int j = 0; j < m; j++)
        for(int i = 0; i < n; i++)
            c[j] += (a[i][j] == '#');


    for(int rows = 0; rows < (1<<n); rows++)
        for(int cols = 0; cols < (1<<m); cols++) {
            set<int> rowsElim, colsElim;
            int rem = black;
            for(int i = 0; (1<<i) <= rows; i++)
                if((1<<i)&rows) rowsElim.insert(i);
            for(int i = 0; (1<<i) <= cols; i++)
                if((1<<i)&cols) colsElim.insert(i);

            for(auto x:rowsElim)
                for(auto y:colsElim)
                    if(a[x][y] == '#')
                        rem++;
            for(auto x:rowsElim)
                rem -= r[x];
            for(auto y:colsElim)
                rem -= c[y];

            if(rem == k) ans++;

        }
    cout << ans;
}
