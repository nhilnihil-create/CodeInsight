#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    ll n;
    cin >> n;
    vector<pair<int,int>>prime;
    int ans = 0;
    for(ll i = 2;i*i<=n;i++) {
        int cnt = 0;
        if(n%i == 0) {
            while(n%i==0) {
                cnt++;
                n /= i;
            }
            int cur = 1;
            while(cnt>=cur) {
                cnt -= cur;
                cur++;
                ans++;
            }
        }
    }
    if(n != 1) ans++;
    cout << ans << endl;
}
    


