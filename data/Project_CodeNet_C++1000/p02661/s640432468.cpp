#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dx[] = { 0, 1, -1, 0, 1, -1, 1, -1 };  // i<4:4way i<8:8way
int dy[] = { 1, 0, 0, -1, 1, -1, -1, 1 };

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<ll> a(n),b(n);
    rep(i,n)cin >> a[i] >> b[i];
    sort(ALL(a));
    sort(ALL(b));
    if(n%2==0){
        ll mi = a[n/2 - 1] + a[n/2];
        ll mx = b[n/2 - 1] + b[n/2];
        cout << mx - mi + 1 << endl;
    }else{
        ll mi = a[n/2], ma = b[n/2];
        cout << ma - mi + 1 << endl;
    }
}