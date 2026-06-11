#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int N, M, Q;
vector<int> a, b, c, d;

int score(vector<int> A) {
    int res = 0;
    rep(i, Q) if (A[b[i]] - A[a[i]] == c[i]) res += d[i];
    return res;
}

int main() {
    cin >> N >> M >> Q;
    a.resize(Q); b.resize(Q); c.resize(Q); d.resize(Q);
    rep(i, Q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--, b[i]--;
    }

    queue<vector<int>> que;
    rep(i, M){
        vector<int> q = {i+1};
        que.push(q);
    }

    int ans = 0;
    while (!que.empty()){
        vector<int> elem = que.front();
        que.pop();
        if (elem.size()==N) ans = max(ans, score(elem));
        else {
            repi(i, elem[elem.size()-1], M+1){
                vector<int> elem_new = elem;
                elem_new.push_back(i);
                que.push(elem_new);
            }
        }
    }
    cout << ans << endl;
}