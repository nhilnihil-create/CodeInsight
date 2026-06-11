#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;


int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    if(n%3!=0){
        if(a[n-1]==0) cout << "Yes" << endl; 
        else cout << "No" << endl;
        return 0;
    }
    int t = n/3;
    if(a[0]==a[t-1] && a[t]==a[2*t-1]&&a[2*t]==a[n-1]) {
        int b = a[0];
        int c = a[t];
        int d = a[2*t];
        int e = b^c;
        if(d==e) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else cout << "No" << endl;
    return 0;
}
