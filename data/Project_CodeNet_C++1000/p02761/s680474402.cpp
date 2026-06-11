#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, char>> sc(m);
    rep(i,m){
        int s;
        char c;
        cin >> s >> c;
        s--;
        sc[i] = make_pair(s, c);
    }


    rep(i, pow(10,n)){
        bool ok = true;
        string iStr = to_string(i);
        if (iStr.size() < n) continue;
        for(auto& scc : sc){
            if (iStr[scc.first] != scc.second) ok = false;
        }
        if (ok){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}