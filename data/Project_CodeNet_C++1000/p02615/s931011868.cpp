#include <bits/stdc++.h>
using namespace std;
#define INF 1e9+7
typedef long long int ll;
const int maxn = 200000;
ll mod = INF;


int main(){

    ll n;
    ll f[maxn];
    ll ans=0;

    cin >> n;
    for(int i=0;i<n;i++)cin >> f[i];

    sort(f,f+n);

    ll cnt=1;

    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            ans+=f[i];cnt++;
        }else if(cnt<=n-2){
            ans+=2*f[i];cnt+=2;
        }else if(cnt==n-1){
            ans+=f[i];cnt++;
        }
        if(cnt==n)break;
    }

    cout << ans<<endl;
    
    return 0;
}