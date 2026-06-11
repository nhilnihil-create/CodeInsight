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
    vector<int>a(n),b(n);
    rep(i,n) {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(n%2==1) {
        int minv = a[n/2];
        int maxv = b[n/2];
        cout << maxv-minv+1 << endl;
        return 0;
    } else {
        int minv = (a[n/2-1]+a[n/2]);
        int maxv = (b[n/2-1]+b[n/2]);
        cout << (maxv-minv)+1 << endl;
    }

}