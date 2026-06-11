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

template<typename T>
struct BIT {
    int n;
    vector<T> d;
    BIT(int n=0):n(n),d(n+1) {}
    void add(int i,T x=1){
        for(i++;i<=n;i += i&-i){
            d[i] += x;
        }
    }
    T sum(int i){
        T x = 0;
        for(i++;i;i-= i&-i) {
            x += d[i];
        }
        return x;
    }
    // 下の2個の操作を使う時は上の2個の操作が使えない事に注意
    T getmax(int i){ // get max(d[i]) for i = 0,1,...,i-1,i
        T x = 0;
        for(i++;i;i-=i&-i) {
            x = max(x, d[i]);
        }
        return x;
    }
    void setmax(int i, int v){ // set d[i] = max(d[i], v)
        for(i++;i<=n;i+=i&-i){
            d[i] = max(d[i], v);
        }
    }
};

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n,k;
    cin >> n >> k;
    vector<int> a(n+1),b(n+1);
    rep(i,n)cin >> a[i];
    for(int i=0;i<k;i++){
        for(int i=0;i<n;i++){
            int left = max(0,i - a[i]);
            int right = min(n-1,i + a[i]);
            b[left]++;
            b[right+1]--;
        }
        for(int i=1;i<n;i++)b[i]+=b[i-1];
        a = b;
        b = vector<int>(n+1);
        bool end = 1;
        rep(i,n){
            if(a[i] != n)end = 0;
            break;
        }
        if(end)break;
    }
    rep(i,n){
        cout << a[i];
        if(i != n-1)cout << " ";
        else cout << endl;
    }
}