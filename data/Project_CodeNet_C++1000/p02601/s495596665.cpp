#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using st = string;
using P = pair<int, int>;
#define mrep(i, m, n) for(int i = m; i < n; i++)
#define rep(i, n) mrep(i, 0, n)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

int main() {
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    int cardA = a, cardB = b, cardC = c;
    int cnt = 0;
    while(cardA >= cardB){
        cardB *= 2;
        cnt++;
    }
    while(cardB >= cardC){
        cardC *= 2;
        cnt++;
    }
    if(cnt <= n) cout << "Yes" << endl;
    else cout << "No" << endl;
}