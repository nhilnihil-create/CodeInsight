#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <algorithm>
#define ii pair<int, int>
#define iii pair<ii, int>
#define pq priority_queue

using namespace std;

vector<int> bfs(vector<vector<int>> adj_list, int start, int n) {
    queue<ii> possible;
    set<int> visited;
    vector<int> no_ways(n - 1, 0);
    possible.push(make_pair(start, 0));
    while (!possible.empty()) {
        int island = possible.front().first;
        int dist_from_start = possible.front().second;
        possible.pop();
        if (visited.find(island) == visited.end()) {
            for (int adj_node : adj_list[island]) {
                possible.push(make_pair(adj_node, dist_from_start + 1));
            }
            if (dist_from_start != 0 && island > start) {
                no_ways[dist_from_start - 1]++;
            }
            visited.insert(island);
        }
    }
    return no_ways;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x, y;
    cin >> n >> x >> y;
    vector<vector<int>> adj_list(n);
    adj_list[0].push_back(1);
    adj_list[n - 1].push_back(n - 2);
    for (int i = 1; i < n - 1; i++) {
        adj_list[i].push_back(i + 1);
        adj_list[i].push_back(i - 1);
    }
    adj_list[x - 1].push_back(y - 1);
    adj_list[y - 1].push_back(x - 1);
    vector<int> answers(n - 1, 0);
    for (int i = 0; i < n; i++) {
        vector<int> ans_from_node = bfs(adj_list, i, n);
        for (int j = 0; j < n - 1; j++) {
            answers[j] += ans_from_node[j];
        }
    }
    for (int i = 0; i < n - 1; i++) {
        cout << answers[i] << '\n';
    }
}