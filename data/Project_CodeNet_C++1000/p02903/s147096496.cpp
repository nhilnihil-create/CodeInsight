#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
void printVec(vector<vector<int>> v) {
    for (int i = 0 ; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            cout << v[i][j];
        }
        cout << '\n';
    }
}
/* main */
int main(){
    int H, W, A, B;
    cin >> H >> W >> A >> B;
    vector<vector<int>> grid(H, vector<int>(W));
    for (int i = 0; i < B; i++) for (int j = A; j < W; j++) grid[i][j] = 1;
    for (int i = B; i < H; i++) for (int j = 0; j < A; j++) grid[i][j] = 1;
    printVec(grid);
}
