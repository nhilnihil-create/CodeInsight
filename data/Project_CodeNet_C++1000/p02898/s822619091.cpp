#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double PI=acos(-1);
const int INF = numeric_limits<int>::max();


int main(){
    ll n;
    int k;
    int h[100001];
    cin >> n >> k;

    int cnt = 0;

    rep(i,n) {
        cin >> h[i];
        if (h[i] >= k) cnt++;        
    }
    
    cout << cnt << endl;

    return 0;
    
}