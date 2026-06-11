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

int main(){
    int N;
    cin >> N;
    int a[N][N];
    int i = 1;
    while(true){
        bool update = false;
        rep(j, N-1){
            rep2(k, j+1, N-1){
                if(j%(1<<(i-1)) == k%(1<<(i-1)) && j%(1<<i) != k%(1<<i)){
                    a[j][k] = i;
                    update = true;
                }
            }
        }
        if(!update) break;
        i++;
    }
    rep(i, N-1){
        rep2(j, i+1, N-1){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}