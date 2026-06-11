#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<vector<int>> Graph;

int main() {
    int n,k,h,ans=0;
    cin >> n >> k;
    rep(i,n){
        cin >> h;
        if (h>=k) ans++;
    }
    cout << ans << endl;
}