#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using st = string;
using P = pair<int, int>;
using bl = bool;
using ch = char;
#define mrep(i, m, n) for(int i = m; i < (n); i++)
#define rep(i, n) mrep(i, 0, n)
#define chmax(x, y) { x = max(x, y); }
#define chmin(x, y) { x = min(x, y); }
#define INF 1e7

vector<int> a(INF);

int main() {
    int k;
    cin >> k;
    a.at(0) = 7 % k;
    mrep(i, 1, k){
        a.at(i) = (a.at(i - 1) * 10 + 7) % k;
    }
    rep(i, k){
        if(a.at(i) == 0){
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    /*while(true){
        if(k % 2 == 0 || k % 5 == 0){
            ans = -1;
            break;
        }
        if(seven % k == 0){
            break;
        }
        seven = seven * 10 + 7;
        ans++;
    }*/
}