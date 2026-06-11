
//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
#include <random>
#include <complex>
#include <regex>
#include <locale>
#include <random>
#include <type_traits>

using namespace std;

#define SHOW_VECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOW_MAP(v){std::cerr << #v << endl; for(const auto& xxx: v){std::cerr << xxx.first << " " << xxx.second << "\n";}}

using LL = long long;

//------------------------------------------
//------------------------------------------

void dfs(vector<int> nodes, vector<pair<int, pair<int, int>>> &edges, int depth) {
    if (nodes.size() <= 1) return;
    vector<int> left, right;
    for (int i = 0; i < nodes.size() / 2; i++) left.push_back(nodes[i]);
    for (int i = nodes.size() / 2; i < nodes.size(); i++) right.push_back(nodes[i]);
    for (int i = 0; i < left.size(); i++) {
        for (int j = 0; j < right.size(); j++) {
            edges.push_back(make_pair(depth, make_pair(left[i], right[j])));
        }
    }
    dfs(left, edges, depth + 1);
    dfs(right, edges, depth + 1);
}

int main() {

    int N;
    cin >> N;

    vector<pair<int, pair<int, int>>> edges;

    vector<int> nodes(N);
    iota(nodes.begin(), nodes.end(), 0);

    dfs(nodes, edges, 0);

    vector<vector<int>> ans(N, vector<int>(N, -1));
    for (int i = 0; i < edges.size(); i++) {
        int level = edges[i].first;
        int f = edges[i].second.first;
        int to = edges[i].second.second;
        ans[f][to] = level + 1;
    }

  //  for (int i = 0; i < N; i++) SHOW_VECTOR(ans[i]);

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1 ; j < N; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

}




























































