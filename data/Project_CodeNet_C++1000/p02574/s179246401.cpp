#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using st = string;
using P = pair<int, int>;
#define mrep(i, m, n) for(int i = m; i < n; i++)
#define rep(i, n) mrep(i, 0, n)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

const int A = 1e6 + 5;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> c(A);
    rep(i, n){
        cin >> a.at(i);
        c.at(a.at(i))++;
    }
    bool pairwise = true;
    mrep(i, 2, A){
        int cnt = 0;
        for(int j = i; j < A; j += i){
            cnt += c.at(j);
        }
        if(cnt > 1) pairwise = false;
    }
    if(pairwise){
        cout << "pairwise coprime" << endl;
        return 0;
    }
    int g = 0;
    rep(i, n) g = gcd(g, a.at(i));
    if(g == 1){
        cout << "setwise coprime" << endl;
        return 0;
    }
    cout << "not coprime" << endl;
    return 0;
}