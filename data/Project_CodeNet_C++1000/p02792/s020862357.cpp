#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
P f(int x){
    int a = x%10;
    int b = 0;
    while (x){
        b = x;
        x /=10;
    }
    return P(a, b);
}
int main() {
    int n;
    cin >> n;
    map<P, int> freq;
    rep(i, 1, n+1){
        P p = f(i);
        freq[p]++;
    }
    ll ans = 0;
    rep(i, 1, n+1){
        P p = f(i);
        P q(p.second, p.first);
        ans += freq[q];
    }
    cout << ans << endl;
    return 0;
}