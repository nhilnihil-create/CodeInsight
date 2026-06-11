#include <bits/stdc++.h>
#define maxn 200010

using namespace std;

int n,a[maxn],s[maxn],m;

int main() {
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];

    while (m--) {
        bool change = true;
        for (int i=1;i<=n;i++) s[i]=0;

        for (int i=1;i<=n;i++) {
            int h = min(n+1,i+a[i]+1);
            int l = max(1,i-a[i]);
            s[l]++;
            s[h]--;
        }

        for (int i=1;i<=n;i++) {
            s[i] = s[i-1] + s[i];
            change &= (a[i]==s[i]);
            a[i] = s[i];
        }
        if (change) break;
    }

    for (int i=1;i<=n;i++) cout<<a[i]<<" ";

}

