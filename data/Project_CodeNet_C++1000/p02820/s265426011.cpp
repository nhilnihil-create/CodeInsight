#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

char hand[100005];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    ll r, p, s;
    string t;
    cin >> n >> k >> r >> s >> p >> t;
    ll ans = 0;
    rep(i,n){
        if(t[i] == 'r'){
            if(i-k < 0 || hand[i-k] != 'p'){
                ans += p;
                hand[i] = 'p';
            }
            else hand[i] = '!';
        }
        else if(t[i] == 's'){
            if(i-k < 0 || hand[i-k] != 'r'){
                ans += r;
                hand[i] = 'r';
            }
            else hand[i] = '!';
        }
        else{
            if(i-k < 0 || hand[i-k] != 's'){
                ans += s;
                hand[i] = 's';
            }
            else hand[i] = '!';
        }
    }
    cout << ans << endl;
    return 0;
}
