#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    string s, t; cin >> s >> t;
    vector<vector<int> > A(50);
    ll ssize = s.size();
    rep(i, ssize){
        int a = s[i] - 'a';
        A[a].push_back(i);
    }

    ll ans = 0;
    int tsize = t.size();
    int now = 0;
    ll cnt = 1;
    rep(i, tsize){
        int b = t[i] - 'a';
        if(A[b].size() == 0){
            cout << -1 << endl;
            return 0;
        }
        int x = lower_bound(A[b].begin(), A[b].end(), now) - A[b].begin();
        if(x != A[b].size()){
            int k = A[b][x];
            ans += k-now + 1;
            now = k+1;
        } else {
            ans = ssize * cnt;
            cnt++;
            now = 0;
            i--;
        }
    }

    cout << ans << endl;

    return 0;
}