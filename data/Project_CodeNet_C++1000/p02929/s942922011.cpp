//order of pair chooosen is doesn't matter. Therefore we only consider choose left/right
#include <bits/stdc++.h>
#define ll long long
#define maxn 200100
#define base 1000000007

using namespace std;

int n,a[maxn];
ll ans=1;
string s;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
   // freopen("input.txt", "r", stdin);
    cin>>n;
    cin>>s;
    a[0] = (s[0]=='W'?0:1);
    for (int i=1;i<2*n;i++) a[i] = (s[i]==s[i-1]?1-a[i-1]:a[i-1]);
    int cnt=0;
    for (int i=0;i<2*n;i++) {
        if (a[i]==0) {
            if (cnt==0) {
                cout<<0;
                return 0;
            }
            ans = (1ll*ans*cnt)%base;
            cnt--;
        } else cnt++;
    }
    if (cnt!=0) {
        cout<<0;
        return 0;
    }
    for (int i=1;i<=n;i++) ans = (1ll*ans*i)%base;
    cout << ans;
}
