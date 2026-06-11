#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main() {
    int n;
    cin>>n;
    vector<ll> a(n),s(n+1),t(n+1);
    ll sum=0;
    rep(i,0,n){
        cin>>a[i];
        sum+=a[i];
    }

    rep(i,0,n){s[i+1]=s[i]+a[i];}
    for(int i=n-1;i>=0;i--){t[i]=t[i+1]+a[i];}

    ll ans = sum;
    rep(i,0,n+1){
        ans=min(ans,abs(s[i]-t[i]));
    }
    cout<<ans<<endl;
    return 0;
}