/* 模範解答 */
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

/*int gcd(int x, int y) {
    if(y == 0){
        return x;
    }
    return gcd(y, x % y);
}*/

/*int gcd(int x, int y) {
    int g;
    vector<int> x_list;
    vector<int> y_list;
    int cnt = 1;
    while(x > cnt){
        if(x % cnt == 0) x_list.push_back(cnt);
        cnt++;
    }
    cnt = 1;
    while(y > cnt){
        if(y % cnt == 0) y_list.push_back(cnt);
        cnt++;
    }
    vector<int> gcd_list;
    int szx = x_list.size();
    int szy = y_list.size();
    rep(i, szx){
        rep(j, szy){
            if(x_list.at(i) == y_list.at(j)) gcd_list.push_back(x_list.at(i));
        }
    }
    int n = gcd_list.size() - 1;
    g = gcd_list.at(n);  
    return g;
}*/

const st pc = "pairwise coprime";
const st sc = "setwise coprime";
const st nc = "not coprime";

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
            cnt += c.at(j); // iの倍数が何個あるかを調べる
        }
        if(cnt > 1) pairwise = false; // 2個以上あったらpairwiseではない
    }
    if(pairwise){
        cout << pc << endl;
        return 0;
    }
    int g = 0;
    rep(i, n) g = gcd(g, a.at(i));
    if(g == 1){
        cout << sc << endl;
        return 0;
    }
    cout << nc << endl;
    return 0;
}