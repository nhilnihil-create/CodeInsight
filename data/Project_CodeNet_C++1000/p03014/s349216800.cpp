#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int N = 1000000;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}

/*------------------------------------------------------------------*/
int digits(ll m){
    int re = 0;
    while(m > 0){
        m /= 10;
        re++;
    }
    return re;
}
int main(){
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    vector<vector<int>> l(h, vector<int>(w, 0));
    vector<vector<int>> r(h, vector<int>(w, 0));
    vector<vector<int>> u(h, vector<int>(w, 0));
    vector<vector<int>> d(h, vector<int>(w, 0));
    vector<vector<int>> total(h, vector<int>(w, 0));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(s[i][j] == '#') l[i][j] = 0;
            else{
                if(j == 0) l[i][j] = 1;
                else l[i][j] = l[i][j - 1] + 1;
            }
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = w - 1; j >= 0; j--){
            if(s[i][j] == '#') r[i][j] = 0;
            else{
                if(j == w - 1) r[i][j] = 1;
                else r[i][j] = r[i][j + 1] + 1;
            }
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(s[i][j] == '#') u[i][j] = 0;
            else{
                if(i == 0) u[i][j] = 1;
                else u[i][j] = u[i - 1][j] + 1;
            }
        }
    }
    for(int i = h - 1; i >= 0; i--){
        for(int j = 0; j < w; j++){
            if(s[i][j] == '#') d[i][j] = 0;
            else{
                if(i == h - 1) d[i][j] = 1;
                else d[i][j] = d[i + 1][j] + 1;
            }
        }
    }
    int ans_max = 0;
    rep(i, h){
        rep(j, w){
            ans_max = max(l[i][j] + r[i][j] + u[i][j] + d[i][j] - 3, ans_max);
        }
    }
    cout << ans_max << endl;
}