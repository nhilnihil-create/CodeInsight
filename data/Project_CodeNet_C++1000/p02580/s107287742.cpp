#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
//https://atcoder.jp/contests/abc176/tasks/abc176_e
vector<pair<int,int>> row, col;
set<pair<int,int>> bombs;

int main() {
    int r, c, m, a, b; scanf("%d %d %d", &r, &c, &m);
    row.resize(r + 1);   col.resize(c + 1);
    for(int i=0; i<=r; i++) row[i].f = 0, row[i].s = i;
    for(int i=0; i<=c; i++) col[i].f = 0, col[i].s = i;

    for(int i=0; i<m; i++) {
        scanf("%d %d", &a, &b);
        
        row[a].f++; col[b].f++;
        bombs.insert({a, b});
    }

    sort(row.begin(), row.end());   // {#bombs in that row, row index}
    sort(col.begin(), col.end());   // {#bombs in that col, col index}

    //printf("ROW: "); for(auto x: row) printf("[%d, idx:%d], ", x.f, x.s);
    //printf("\nCOL: "); for(auto x: col) printf("[%d, idx:%d], ", x.f, x.s);

    int ans = 0;

    if(bombs.find({row[r].s, col[c].s}) == bombs.end()) ans = row[r].f + col[c].f;   // no bomb here at this cell
    else if(r == 1) ans = row[1].f;   // no other choice, in next line as well
    else if(c == 1) ans = col[1].f;
    else {
        ans = row[r].f + col[c].f - 1;  // this cell added twice

        int idx = r - 1;
        while(bombs.find({row[idx].s, col[c].s}) != bombs.end()) idx--;  // where there is empty cell in that col
        ans = max(ans, row[idx].f + col[c].f);

        idx = c - 1;
        while(bombs.find({row[r].s, col[idx].s}) != bombs.end()) idx--; // where there is empty cell in that row
        ans = max(ans, row[r].f + col[idx].f);        
    }

    printf("%d\n", ans);
    return 0;
}