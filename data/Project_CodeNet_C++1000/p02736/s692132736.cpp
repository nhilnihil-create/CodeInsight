#include <bits/stdc++.h>
#define ll long long
#define int128 __int128_t
#define Android ios::sync_with_stdio(false), cin.tie(NULL)
#define redirect_input freopen("./input.txt", "r", stdin);
#define redirect_output freopen("./output.txt", "w", stdout);
#define debug(s, r) std::cerr << #s << ": " << (s) << (r==0?' ':'\n')
#define pii pair<int, int>  
#define sqr(x) ((x)*(x))

using namespace std;

const int maxn = 1e6 + 1000;

char val[2][maxn];

bool isSubmask(ll ori, ll test){
    return (ori & test) == test;
}

void solve(){
    int n; cin >> n;
    cin >> val[0];
    for(int i=0; i<n; i++) val[0][i] -= 0;
    if(n == 1) {
        cout << (int)val[0][0] << '\n';
        return;
    }
    n--;
    for(int i=0; i<n; i++) val[1][i] = abs(val[0][i] - val[0][i+1]);
    char * arr = val[1];
    if(n == 1){
        cout << (int)arr[0] << endl;
        return;
    }
    bool one_exist = false;
    int parity_1 = 0, parity_2 = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == 1){
            parity_1 = (parity_1 + isSubmask(n - 1, i)) % 2;
            one_exist = true;
        }
        if(arr[i] == 2){
            parity_2 = (parity_2 + isSubmask(n - 1, i)) % 2;
        }
    }
    int ans = 1;
    if(parity_1 == 0){
        if(!one_exist && parity_2 == 1) ans = 2;
        else ans = 0;
    }
    cout << ans << '\n';
}

signed main(){
    Android;
    solve();
}
