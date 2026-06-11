#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    vector<vector<pair<int, int>>>p(h, vector<pair<int, int>>(w));
    rep(i, h){
        queue<int> q;
        int cnt = 0;
        rep(j, w){
            if (s[i][j] == '.') {
                q.push(j);
            }else{
                cnt = q.size();
                rep(k, cnt) {
                    p[i][q.front()].first = cnt;
                    q.pop();
                }
            }
        }
        cnt = q.size();
        rep(k, cnt) {
            p[i][q.front()].first = cnt;
            q.pop();
        }
    }
    rep(i, w){
        queue<int> q;
        int cnt = 0;
        rep(j, h){
            if (s[j][i] == '.') {
                q.push(j);
            }else{
                cnt = q.size();
                rep(k, cnt) {
                    p[q.front()][i].second = cnt;
                    q.pop();
                }
            }
        }
        cnt = q.size();
        rep(k, cnt) {
            p[q.front()][i].second = cnt;
            q.pop();
        }
    }
    int ans = 0;
    rep(i, h){
        rep(j, w){
            //cout << '(' << p[i][j].first << ',' << p[i][j].second <<  ") ";
            if (s[i][j] == '.') {
                ans = max(ans, p[i][j].first + p[i][j].second - 1);
            }
        }
        //cout << endl;
    }
    cout << ans << endl;
    return 0;
}
