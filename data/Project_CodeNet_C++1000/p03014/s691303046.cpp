#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int h,w;    cin >> h >> w;
    vector<string>s(h);
    rep(i, h)   cin >> s[i];
    vector<vector<int>>row_ptr(h, vector<int>(1, -1));
    rep(i, h){
        rep(j, w){
            if(s[i][j] == '#')  row_ptr[i].push_back(j);
        }
        row_ptr[i].push_back(w);
    }
    vector<vector<int>>col_ptr(w, vector<int>(1, -1));
    rep(i, w){
        rep(j, h){
            if(s[j][i] == '#')  col_ptr[i].push_back(j);
        }
        col_ptr[i].push_back(h);
    }
    int ans = 0;
    rep(i, h)   rep(j, w){
        if(s[i][j] == '#')  continue;
        int tmp = 0;
        /*
         * row
         */
        int l = 0, r = row_ptr[i].size()-1;
        while(l+1<r){
            int m = (l+r)/2;
            if(row_ptr[i][m] > j)  r = m;
            else                l = m;
        }
        tmp += row_ptr[i][r]-row_ptr[i][l]-1;
        /*
         * col
         */
        l = 0;  r = col_ptr[j].size()-1;
        while(l+1<r){
            int m = (l+r)/2;
            if(col_ptr[j][m] > i)  r = m;
            else                l = m;
        }
        tmp += col_ptr[j][r]-col_ptr[j][l]-1;
        ans = max(ans, tmp-1);
    }
    cout << ans << endl;
}
