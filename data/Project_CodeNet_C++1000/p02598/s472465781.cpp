#include <bits/stdc++.h>
using namespace std;
#define INF 1e9+7
typedef long long int ll;
const int maxn = 200000;
ll mod = INF;

ll n;
ll k;
ll a[maxn];
ll ans;

int main(){

    cin >> n>>k;
    for(int i=0;i<n;i++)cin >> a[i];

    sort(a,a+n);

    ll l=0,r=a[n-1]+1;
    int idx=0;
    ll ans =a[n-1];

    while(r-l>1){
        bool key=true;
        ll mid=(l+r)/2.0;
        ll cnt=0;
        for(int i=0;i<n;i++){
            cnt+=(ll)((a[i]-1)/mid);
        }
        if(cnt>k)key=false;

        if(key){
            ans=(ll)ceil(mid);
            r=mid;
        }else{
            l=mid;
        }
        idx++;
    }

    cout << ans<<endl;

    return 0;
}