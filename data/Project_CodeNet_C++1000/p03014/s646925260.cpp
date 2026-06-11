#include <iostream>
#include <algorithm>
#include <map>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i=0; i< (int)(n); i++)
typedef long long ll;
bool DEBUG = false;


int main() {
    int H,W;
    cin >> H >> W;

    vector<vector<char>> grid(H);
    rep(i, H){
        string si;
        cin >> si;
        rep(j,W){
            grid[i].push_back(si[j]);
        }
    }

    vector<vector<int>> horizontal(H);
    vector<vector<int>> vertical(H);
    if (DEBUG) cout << "input done" << endl;

    // horizontal direction
    rep(row, H){
        vector<int> blocks;
        blocks.push_back(-1);
        rep(col, W){
            if (grid[row][col] == '#'){
                blocks.push_back(col);
            }
        }
        blocks.push_back(W);
        if (DEBUG) cout << "blocks created for row: " << row << endl;

        // [-1, 0, 1]
        // h: [ ]
                if (DEBUG) {
            cout << "blocks are ";
            rep(i, blocks.size()) {
                cout << blocks[i] << " ";
            } 
            cout << endl;
        }
        int bsize = (int) blocks.size();
        if (DEBUG) cout << "w" << endl;

        for (int bi = 0; bi < bsize - 1; bi++){ // i:3
            if (DEBUG) cout << "x" << endl;

            if (bi != 0) horizontal[row].push_back(0); // horizontal[blocks[i]] = 0;
            int val_insert = blocks[bi+1] - blocks[bi] - 1;
            if (DEBUG) cout << "y"<< endl;
            rep(j, val_insert){
                // horizontal[blocks[i] + 1 + j] = val_insert;
                if (DEBUG) cout << "z1" << endl;
                
                horizontal[row].push_back(val_insert);
                if (DEBUG) cout << "z" << endl;
            }
        }
        vector<int>().swap(blocks);
    }
    if (DEBUG) cout << "horizontal done" << endl;

    // vertical direction
    rep(col, W){
        vector<int> blocks;
        blocks.push_back(-1);
        rep(row, H){
            if (grid[row][col] == '#'){
                blocks.push_back(row);
            }
        }
        blocks.push_back(H);
        if (DEBUG) cout << "blocks created for col: " << col << endl;

        // blocks: [-1, 0, 3, 4]
        if (DEBUG) {
            cout << "blocks are ";
            rep(i, blocks.size()) {
                cout << blocks[i] << " ";
            } 
            cout << endl;
        }
        for (int i = 0; i < (int) blocks.size() - 1; i++){ // i: 1
            if (i != 0) vertical[blocks[i]].push_back(0); // vertical[blocks[i]] = 0;
            int val_insert = blocks[i+1] - blocks[i] - 1;
            rep(j, val_insert){
                // vertical[blocks[i] + 1 + j] = val_insert;
                vertical[blocks[i] + j + 1].push_back(val_insert);
            }
        }
        if (DEBUG) cout << "vales added for col: " << col << endl;
    }
    if (DEBUG) cout << "vertical done" << endl;

    // calc sum
    int ans = 0;
    rep(i, H){
        rep(j, W){
            ans = max(horizontal[i][j]+vertical[i][j], ans);
        }
    }

    cout << ans - 1 << endl;

}