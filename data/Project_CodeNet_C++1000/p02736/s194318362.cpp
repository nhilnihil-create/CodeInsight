#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

//a!が2で何回割り切れるか
int log2(int a){
    int sum = 0;
    while(a > 0){
        sum += a/2;
        a /= 2;
    }
    return sum;
}

int main(){
    int N;
    cin >> N;
    int a[N];
    string s;
    cin >> s;
    bool exist[3];
    fill(exist, exist+3, false);
    rep(i, N){
        a[i] = s[i]-'1';
        exist[a[i]] = true;
    }
    bool sub = false;
    if(exist[0] && exist[2] && !exist[1]){
        sub = true;
        rep(i, N) a[i] /= 2;
    }
    int ans = 0;
    rep(i, N){
        //cout << a[i] << endl;
        if(a[i]%2){
            int x = log2(N-1)-log2(N-1-i)-log2(i);
            if(x == 0) ans ^= 1;
        }
    }
    if(sub) ans *= 2;
    cout << ans << endl;
}