#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;



template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;

int main() {
    int H, W;
    cin >> H >> W;
    string S;
    vector<vector<int>> maze(H, vector<int>(W));
    rp(i, 0, H) {
        cin >> S;
        rp(j, 0, W) {
            if(S[j] == '#') maze.at(i).at(j) = 0;
            else maze.at(i).at(j) = 1;
        }
    }

    vector<vector<int>> line(H, vector<int>(W));
    vector<vector<int>> row(H, vector<int>(W));
    int ans = 0;
    rp(i, 0, H) {
        rp(j, 0, W) {
            if(maze[i][j] == 1) {
                if(i-1 >= 0 && maze.at(i-1).at(j) != 0) {
                    line.at(i).at(j) = line.at(i-1).at(j);
                }
                else {
                    int end = i;
                    while(maze.at(end).at(j) == 1) {
                        end++;
                        if(end>=H) break;
                    }
                    line.at(i).at(j) = end - i;
                }

                if(j-1 >= 0 && maze.at(i).at(j-1) != 0) {
                    row.at(i).at(j) = row.at(i).at(j-1);
                }
                else {
                    int end = j;
                    while(maze.at(i).at(end) == 1) {
                        end++;
                        if(end>=W) break;
                    }
                    row.at(i).at(j) = end - j;
                }
                chmax(ans, line[i][j] + row[i][j] - 1);
                // printf("(i, j) = (%d, %d) line: %d row = %d\n", i, j, line[i][j], row[i][j]);
            }
        }
    }
    cout << ans << endl; 
    return 0;

}