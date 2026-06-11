#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    rep(i,n) cin >> a[i];
    ll offset = 0;
    rep(i,n) offset = 2*a[i]-offset;
    ll x = offset/2;
    rep(i,n) {
        cout << x << " ";
        x = 2*a[i] -x;
    }
    cout << endl;
    
}