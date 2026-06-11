#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void p(vector<int> A){rep(i,A.size()){cout << A[i];}cout << endl;}

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    rep(i,n+1) cin >> a[i];
    vector<int> b(n);
    rep(i,n) cin >> b[i];
    ll ans = 0;
    rep(i,n){
        int left = min(b[i],a[i]);
        ans += left;
        a[i] -= left;
        b[i] -= left;
        int right = min(b[i],a[i+1]);
        ans += right;
        a[i+1] -= right;
        b[i] -= right; 
    }
    cout << ans;
}