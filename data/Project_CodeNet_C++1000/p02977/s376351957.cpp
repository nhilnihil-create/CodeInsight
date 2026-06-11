#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

void out(int a, int b){
    cout << a << ' ' << b << endl;
}

int main(){
    int N;
    cin >> N;
    int memo = N;
    while(memo%2 == 0) memo /= 2;
    if(memo == 1) {cout << "No" << endl; return 0;}
    cout << "Yes" << endl;
    if(N%4 == 1){
        rep2(i, 2, N-1) out(i, i+1);
        out(N, N+2);
        rep2(i, 2, N-1) out(N+i, N+i+1);
        out(1, N+2), out(N+1, N+3);
    }elif(N%4 == 2){
        rep2(i, 2, N-2) out(i, i+1);
        out(N-1, N+2);
        rep2(i, 2, N-2) out(N+i, N+i+1);
        out(1, N+2), out(N+1, N+3);
        out(N-1, N), out(1, 2*N);
    }elif(N%4 == 3){
        rep2(i, 1, 2*N-1) out(i, i+1);
    }else{
        int a = N & (-N);
        rep2(i, 1, N-2) out(i, i+1);
        out(N-1, N+1);
        rep2(i, 1, N-2) out(N+i, N+i+1);
        out(N-a+1, N), out(N+a, 2*N);
    }
}