#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 100000;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<P>AB(N);
    for(int i = 0; i < N; i++) {
        int A,B;
        cin >> A >> B;
        AB[i].first = B;
        AB[i].second = A;
    }
    sort(AB.begin(),AB.end());
    int now = 0;
    for(int i = 0; i < N; i++) {
        now+=AB[i].second;
        if(now > AB[i].first) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
