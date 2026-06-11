#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include<cmath>
#include<limits>
#define ll long long
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9223372036854775807
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvc vector<vector<char>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define sysp system("PAUSE")
#define pno cout << "no" << endl
#define pyes cout << "yes" << endl
#define pYes cout << "Yes" << endl
#define pNo cout << "No" << endl
using namespace std;

class DFS {
private:
    vector<vector<int>> Graph;
    vector<int> Value;
    vector<int> Acc;
    vector<bool> isVisited;
public:
    void init(int N) {
        Graph.resize(N);
        Value.resize(N, 0);
        isVisited.resize(N, false);
        Acc.resize(N);
        for (int i = 0; i < N - 1; i++) {
            int a, b; cin >> a >> b;
            --a; --b;
            Graph[a].push_back(b);
            Graph[b].push_back(a);
        }
    }

    void SetValue(int p, int x) {
        Value[p] += x;
    }

    int next(int u) {
        for (auto& elem : Graph[u]) {
            if (isVisited[elem] == false) {
                isVisited[elem] = true;
                return elem;
            }
        }
        return -1;
    }

    void DepthFirstSearch(int start) {
        stack<int> S;
        S.push(start);
        Acc[start] = Value[start];
        isVisited[start] = true;
        while (!S.empty()) {
            int u = S.top();
            int v = next(u);

            if (v == -1) {
                S.pop();
                continue;
            }
            else {
                Acc[v] = Acc[u] + Value[v];
                S.push(v);
            }
        }
    }

    void BreadsFirstSearch(int start) {
        queue<int> q;
        q.push(start);
        Acc[start] = Value[start];
        isVisited[start] = true;

        while (!q.empty()) {
            int u = q.front();
            for (auto v : Graph[u]) {
                if (isVisited[v] == false) {
                    q.push(v);
                    Acc[v] = Acc[u] + Value[v];
                    isVisited[v] = true;
                }
            }
            q.pop();
        }
    }
    vector<int> ans() {
        return Acc;
    }
};
int main() {
    int N, Q; cin >> N >> Q;
    DFS dfs;
    dfs.init(N);
    for (int t = 0; t < Q; t++) {
        int p, x; cin >> p >> x;
        --p;
        dfs.SetValue(p, x);
    }
    dfs.BreadsFirstSearch(0);
    vi ans = dfs.ans();
    for (auto& elem : ans) {
        cout << elem << " ";
    }
}