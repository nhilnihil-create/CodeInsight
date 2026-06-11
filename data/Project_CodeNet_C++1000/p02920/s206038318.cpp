#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    multiset<int> A;
    for(int i=0; i<(1<<N); ++i) {
        int a; cin >> a;
        A.insert(-a);
    }

    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, *begin(A));
    A.erase(begin(A));
    while(!que.empty()) {
        P cur = que.top();
        int val = cur.second, depth = cur.first;
        que.pop();
        auto itr = A.upper_bound(val);
        if(itr == end(A)) {
            cout << "No" << endl;
            return 0;
        } else if(depth < N - 1) {
            que.emplace(depth + 1, val);
            que.emplace(depth + 1, *itr);
        }
        A.erase(itr);
    }

    cout << "Yes" << endl;
}