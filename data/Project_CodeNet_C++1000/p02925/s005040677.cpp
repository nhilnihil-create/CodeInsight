#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> p;
 
#define MOD 1000000007
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<vector<int> > A(N, vector<int>(N - 1));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N - 1; j++) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }

    vector<p> q;
    vector<p> k;

    vector<vector<int> > v(N, vector<int>(N));

    vector<int> pos(N);

    for(int i = 0; i < N; i++) {
        int a = A[i][pos[i]];
        int b = i;
        if(b < a) swap(a, b);
        v[a][b]++;
        if(v[a][b] == 2) {
            q.push_back(make_pair(a, b));
        }
    }

    int ans = 0;

    while(!q.empty()) {
        ans++;
        for(int i = 0; i < q.size(); i++) {
            int a = q[i].first;
            int b = q[i].second;
            pos[a]++;
            pos[b]++;
            if(pos[a] < N - 1) {
                int c = a;
                int d = A[c][pos[c]];
                if(d < c) swap(c, d);
                v[c][d]++;
                if(v[c][d] == 2) {
                    k.push_back(make_pair(c, d));
                }
            }
            if(pos[b] < N - 1) {
                int c = b;
                int d = A[c][pos[c]];
                if(d < c) swap(c, d);
                v[c][d]++;
                if(v[c][d] == 2) {
                    k.push_back(make_pair(c, d));
                }
            }
        }

        q.clear();

        for(int i = 0; i < k.size(); i++) {
            q.push_back(k[i]);
        }

        k.clear();
    }

    for(int i = 0; i < N - 1; i++) {
        for(int j = i + 1; j < N; j++) {
            if(v[i][j] != 2) {
                cerr << i << " " << j << endl;
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << ans << endl;
}