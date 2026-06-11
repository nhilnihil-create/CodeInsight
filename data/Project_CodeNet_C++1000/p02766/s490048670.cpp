#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define REP(i,n) for (int i=1;i<=(n);i++)
typedef long long ll;

int main() {
    int n,k;
    cin >> n >> k;
    int ans = 0;
    while(n>0){
        n=n/k;
        ans++;
    }
    cout << ans << endl;
}