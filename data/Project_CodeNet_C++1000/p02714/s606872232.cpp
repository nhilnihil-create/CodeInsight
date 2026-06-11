#include <bits/stdc++.h>
#include <math.h>
#define rep(i,n) for (int i=0;i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
 
 
int main() {
    ll n,ans=0;
    string S;
    cin >> n >> S;
    vector<int> a(n);
    rep(i,n) {
        if(S[i]=='R') a[i]=0;
        else if (S[i]=='G') a[i]=1;
        else a[i]=2;
    }
    vector<ll> cnt(3);
    rep(i,n) {
        cnt[a[i]]++;
    }
    rep(j,n) rep(i,j){
        int k = j + (j-i);
        if(k<n){
            if (a[i]==a[j]||a[i]==a[k]||a[j]==a[k]) continue;
            ans--;
        }
    }
    ans += cnt[0]*cnt[1]*cnt[2];
    cout << ans << endl;
}