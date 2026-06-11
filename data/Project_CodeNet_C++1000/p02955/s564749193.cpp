#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn = 500+10;
LL a[maxn];
LL b[maxn];
LL ans = 1;
int n,k;

void update(LL x){
    LL t = 0;
    for(int j = 1;j <= n; ++j)
        b[j] = a[j]%x, t += b[j];
    sort(b+1,b+n+1,greater<LL>());
    LL tt = t;
    for(int j = 1;j <= tt/x; ++j)
        t -= b[j];
    if(t <= k)
        ans = max(ans,x);
}
int main(void)
{
    cin>>n>>k;
    LL sum = 0;
    for(int i = 1;i <= n; ++i)
        cin>>a[i],sum += a[i];
    // cout<<sum<<endl;
    for(LL i = 2;i*i <= sum; ++i){
        if(sum % i == 0){
            update(i);
            update(sum/i);
        }
    }
    update(sum);

    cout<<ans<<endl;

    return 0;
}

