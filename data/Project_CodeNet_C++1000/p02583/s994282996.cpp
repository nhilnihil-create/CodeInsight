#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define REP(i,n) for (int i=1;i<=(n);i++)
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    int ans = 0;
    sort(l.begin(),l.end());
    for(int i=0;i<=n-3;i++){
        for(int j=i+1;j<=n-2;j++){
            for(int k=j+1;k<=n-1;k++){
                if(l[i]!=l[j]&&l[j]!=l[k]&&l[i]+l[j]>l[k]) ans++;
            }
        }
    }
    cout << ans << endl;
}