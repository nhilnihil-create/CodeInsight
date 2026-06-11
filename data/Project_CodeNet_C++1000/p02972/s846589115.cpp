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
    vector<int>a(n+1);
    rep(i,n) cin >> a[i+1];
    vector<int>b(n+1);
    int ans = 0;
    for(int i = n;i>=1;i--) {
        int sum = 0;
        for(int j = i+i;j<=n;j += i) {
            sum += b[j];
        }
        if(sum%2 != a[i]) {
            ans++;
            b[i]++;
        }    
    } 
    cout << ans << endl;
    rep(i,n+1) {
        if(b[i])cout << i <<" ";
    }
    cout << endl;
}