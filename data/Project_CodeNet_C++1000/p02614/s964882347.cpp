#include <bits/stdc++.h>

using namespace std;

int helpercol(int j, int h, int w, int k, int total, vector<vector<char>> &sq, vector<bool> &rows) {
    if (total < 0) {
        return 0;
    }
    int black = 0;
    int solutions = 0;
    for (int i = 0; i < h; i++) {
        if (rows[i] == 0 && sq[i][j] == '#') {
            black += 1;
        }
    }
    if (total - black == k) {
        solutions += 1;
    }
    for (int i = j + 1; i < w; i++) {
        solutions += helpercol(i, h, w, k, total - black, sq, rows);
    }
    return solutions;
}
    
int helper(int i, int h, int w, int k,int total, vector<vector<char>> &sq, vector<bool> &rows){
    if (total < 0) {
        return 0;
    }
    int black = 0;
    int solutions = 0;
    for (int j = 0; j < w; j++) {
        if (sq[i][j] == '#') {
            black += 1;
        }
    }
    if (total - black == k) {
        solutions += 1;
    }
    rows[i] = 1;
    for (int j = 0; j < w; j++) {
        solutions += helpercol(j,h,w,k,total-black,sq,rows);
    }
    for (int j = i + 1; j < h; j++) {
        vector<bool> nrow = rows;
        solutions += helper(j,h,w,k,total-black,sq,nrow);
    }
    return solutions;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<char>> sq;
    char c;
    int total = 0;
    for (int i = 0; i < h; i++) {
        sq.push_back(vector<char> ());
        for (int j = 0; j < w; j++) {
            cin >> c;
            if (c == '#') {
                total += 1;
            }
            sq[i].push_back(c);
        }
    }
    int solutions = 0;
    if (total == k) {
        solutions += 1;
    }
    vector<bool> rows(h,0);
    for (int j = 0; j < w; j++) {
        solutions += helpercol(j,h,w,k,total,sq,rows);
    }   
    for (int i = 0; i < h; i++) {
        vector<bool> rows(h,0);
        solutions += helper(i,h,w,k,total,sq,rows);
    }
    cout << solutions;
}
