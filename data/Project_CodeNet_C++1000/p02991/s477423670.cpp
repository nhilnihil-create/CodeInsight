#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<ll, ll> p;
 
#define MOD 1000000007
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<vector<int> > v(N);

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
    }

    int S, T;
    cin >> S >> T;
    S--;
    T--;

    vector<vector<bool> > b(N, vector<bool>(3));

    queue<p> q;

    q.push(make_pair(S, 0));

    while(!q.empty()) {
        int x = q.front().first;
        int c = q.front().second;
        q.pop();
        if(b[x][c % 3]) continue;
        b[x][c % 3] = true;
        if(x == T && c % 3 == 0) {
            cout << c / 3 << endl;
            return 0;
        }
        c++;
        for(int i = 0; i < v[x].size(); i++) {
            q.push(make_pair(v[x][i], c));
        }
    }

    cout << -1 << endl;
}