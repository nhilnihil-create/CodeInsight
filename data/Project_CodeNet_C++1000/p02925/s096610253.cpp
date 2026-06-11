#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
template<class T, class U> inline bool chmax(T& a,U b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class U> inline bool chmin(T& a,U b) { if (a > b) { a = b; return 1; } return 0; }    

int main() {
    int N;
    cin >> N;
    vector<queue<int>> data(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N-1; j++) {
            int a; cin >> a; --a;
            data[i].emplace(a);
        }
    }
    
    int ans = 0;
    bool play[N] = {0};
    queue<int> que;
    for (int i = 0; i < N; i++) que.emplace(i);
    
    while (que.size()) {
        fill(play, play + N, false);
        queue<int> next;
        while (que.size()) {
            int me = que.front(); que.pop();
            if (data[me].empty()) continue;
            int you = data[me].front();
            if (data[you].front() == me && !play[me] && !play[you]) {
                next.emplace(me); next.emplace(you);
                if (data[me].size()  > 0) data[me].pop();
                if (data[you].size() > 0) data[you].pop();
                play[me] = play[you] = true;
            }
        }
        swap(que, next);
        ans++;
    }
    
    bool fin = true;
    for (int i = 0; i < N; i++) if (data[i].size() > 0) fin = false;
    
    cout << ((fin) ? ans-1 : -1) << endl;
    return 0;
}