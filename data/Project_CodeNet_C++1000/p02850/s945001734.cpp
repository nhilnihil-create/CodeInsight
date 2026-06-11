#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef pair<int, int> P;

int n;
vector< vector<int> > graphlist(100100, vector<int>());
vector<int> avec(100100, 0);
vector<int> bvec(100100, 0);
vector< set<int> > colorlist(100100, set<int>());
vector<bool> visited(100100, false);

int main() {
    cin >> n;
    map<P, int> edge;
    for(int i = 0; i < n-1; ++i) {
        int aa, bb; cin >> aa >> bb; aa--; bb--;
        avec.at(i) = aa; bvec.at(i) = bb;
        graphlist.at(aa).emplace_back(bb);
        graphlist.at(bb).emplace_back(aa);
        edge[P(aa, bb)] = 0;
        edge[P(bb, aa)] = 0;
    }

    queue<int> que;
    que.push(0);
    while(!que.empty()) {
        int now = que.front();
        que.pop();
        visited.at(now) = true;
        int incolor = 1;
        for(int i = 0; i < graphlist.at(now).size(); ++i) {
            int next = graphlist.at(now).at(i);
            if(visited.at(next)) continue;
            if(colorlist.at(now).count(incolor) == 0) {
                colorlist.at(now).insert(incolor);
                colorlist.at(next).insert(incolor);
                edge[P(now, next)] = incolor;
                edge[P(next, now)] = incolor;
                incolor++;
                que.push(next);
            }else {
                incolor++;
                colorlist.at(now).insert(incolor);
                colorlist.at(next).insert(incolor);
                edge[P(now, next)] = incolor;
                edge[P(next, now)] = incolor;
                incolor++;
                que.push(next);
            }
        }
    }

    set<int> ans;
    for(int i = 0; i < n-1; ++i) {
        ans.insert(edge[P(avec.at(i), bvec.at(i))]);
    }

    cout << ans.size() << endl;
    for(int i = 0; i < n-1; ++i) {
        cout << edge[P(avec.at(i), bvec.at(i))] << endl;
    }
}