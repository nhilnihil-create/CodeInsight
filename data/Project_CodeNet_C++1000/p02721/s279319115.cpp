#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int l[200010];
int r[200010];

int main(){
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;

    int num = 0;
    int now = 0;
    while(now < n){
        if (s[now] == 'o'){
            l[++num] = now;
            now += c + 1;
        } else{
            now++;
        }
    }

    num = k;
    now = n - 1;
    while(now >= 0){
        if (s[now] == 'o'){
            r[num--] = now;
            if (num <= 0) break;
            now -= c + 1;
        } else{
            now--;
        }
    }

    for (int i = 1; i <= k; ++i) {
        if (l[i] == r[i]){
            cout << l[i] + 1 << endl;
        }
    }
}