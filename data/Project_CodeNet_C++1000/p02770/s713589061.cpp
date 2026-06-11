#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int k,q; cin >> k >> q;
    vector<ll> d(k),a(k);
    for (int i=0;i<k;++i) cin >> d[i];
    ll n,x,m,sum,cnt,cnt1,cnt2,ans;
    for (int i=0;i<q;++i){
        cin >> n >> x >> m;
        sum=cnt1=cnt2=0,cnt=x%m;
        for (int j=0;j<k;++j){
            a[j]=d[j]%m; sum+=a[j];
            if (!a[j]) ++cnt1;
            if (j<(n-1)%k){
                cnt+=a[j];
                if (!a[j]) ++cnt2;
            }
        }
        cnt+=(n-1)/k*sum;
        ans=n-1-cnt/m-(n-1)/k*cnt1-cnt2;
        cout << ans << endl;
    }
}