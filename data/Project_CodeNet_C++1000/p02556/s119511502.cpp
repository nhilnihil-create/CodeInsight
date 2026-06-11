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
    vector<int>b(n);
    rep(i,n) {
        int x,y;
        cin >> x >> y;
        a[i] = x+y;
        b[i] = x-y;
    }
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    int ans = max(abs(a[n-1]-a[0]),abs(b[0]-b[n-1]));
    cout << ans << endl;
}