#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int d,m,ans=0;
    cin>>m>>d;
    for (int i=2;i<=9;i++)
        for (int j=2;j<=9;j++) {
            int nm = i*j;
            ans+=(10*i+j<=d && nm<=m);
        }
    cout << ans;

}
