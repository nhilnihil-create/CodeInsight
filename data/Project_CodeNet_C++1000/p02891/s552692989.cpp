#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int cnt[100];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    long long k;
    cin >> s >> k;
    int n = s.length();
    if(n == 1){
        cout << k/2 << endl;
        return 0;
    }
    int p = 0;
    char pre = s[0];
    for(int i = 0; i < n; i++){
        if(s[i] == pre){
            cnt[p]++;
        }
        else{
            cnt[++p]++;
            pre = s[i];
        }
    }
    if(p == 0){
        cout << n*k/2 << endl;
        return 0;
    }
    long long ans = 0;
    for(int i = 0; i <= p; i++){
        ans += cnt[i]/2;
    }
    ans *= k;
    if(s[0] == s[n-1])
        ans -= (cnt[0]/2 + cnt[p]/2 - ((cnt[0]+cnt[p])/2)) * (k-1);
    cout << ans << endl;
    return 0;
}
