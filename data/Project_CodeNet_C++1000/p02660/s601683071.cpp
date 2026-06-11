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
    for(ll i = 2;i*i<=n;i++) {
        if(n%i == 0) {
            int cnt = 0;
            while(n%i==0) {
                cnt++;
                n /= i;
            }
            prime.push_back(make_pair(i,cnt));
        }
    }
    if(n != 1) prime.push_back(make_pair(n,1));
    int ans = 0;
    for(auto p : prime) {
        int tmp = 0;
        int lim = p.second;
        for(ll i = 1;i*(i+1)<=2*lim;i++) {
            tmp++;
        }
        ans += tmp;
    }
    cout << ans << endl;
}

