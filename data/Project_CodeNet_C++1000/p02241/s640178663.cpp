#include <bits/stdc++.h>

using namespace std;

#define Vi vector<int>
#define FOR(i,s,e) for (int i=s; i<e; i++)
#define ITER(v) v.begin(), v.end()

constexpr int N_MAX = 100;

int weight[N_MAX][N_MAX];

int mst(const int n) {
    bool ismember[n] = {false};
    Vi members;

    members.push_back(0);
    ismember[0] = true;
    int cost = 0;

    FOR(t,1,n) {
        int addcost = -1;
        int newmember = -1;
        for (const int i : members)
        FOR(j,0,n) {
            if (ismember[j]) { continue; }
            const int w = weight[i][j];
            if (w < 0) { continue; }
            if (addcost < 0 || addcost > w) {
                addcost = w;
                newmember = j;
            }
        }
        members.push_back(newmember);
        ismember[newmember] = true;
        cost += addcost;
        //cout << "#" << newmember << endl;
    }
    return cost;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    FOR(i,0,n) {
        FOR(j,0,n) {
            cin >> weight[i][j];
        }
    }

    int cost = mst(n);
    cout << cost << endl;

    return 0;
}