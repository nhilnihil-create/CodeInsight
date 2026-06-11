#include <bits/stdc++.h>
using namespace std;
#define int long long
int N;

const int MAX_N = 1001;
const int MAX_GAME = MAX_N * MAX_N;

bool visited[MAX_GAME];
bool calced[MAX_GAME];
int day[MAX_GAME];
int get_day(int game, vector<vector<int>>& prev) {
    if (visited[game]) {
        if (!calced[game]) return -1;
        return day[game];
    }
    visited[game] = true;
    day[game] = 1;
    for(int prev_game : prev[game]) {
        int prev_game_day = get_day(prev_game, prev);
        if (prev_game_day == -1) return -1;
        day[game] = max(day[game], prev_game_day + 1);
    }
    calced[game] = true;
    return day[game];
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N - 1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }
    int index = 0;
    vector<vector<int>> game_id(N, vector<int>(N));
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            game_id[i][j] = index;
            game_id[j][i] = index;
            index++;
        }
    }
    vector<vector<int>> prev(N * (N - 1) / 2, vector<int>());
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 2; j++ ) {
            prev[game_id[i][A[i][j + 1]]].push_back(game_id[i][A[i][j]]);
        }
    }
    int last = 0;
    for (int g = 0; g < N * (N - 1) / 2; g++) {
        int day = get_day(g, prev);
        if (day == -1) {
            cout << -1 << endl;
            return 0;
        }
        last = max(last, day);
    }
    cout << last << endl;
    return 0;
}