#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
ll arr[5001] , score [5001] , vis[5001];
ll n  , k ;
const ll OO =-1e18;
ll mx;
ll cycleLen(ll idx)
{
    if(vis[idx])
        return 0;
    vis[idx]++;
    ll cnt=cycleLen(arr[idx])+1;
    return cnt;
}
ll cycleVal( ll idx , ll num , ll scsofar , ll MX)
{
    if(vis[idx])
        return 0;
    vis[idx]++;
    scsofar+=score[arr[idx]];
    num++;
    if(num<=MX)mx=max(mx , scsofar);
    ll ans=cycleVal(arr[idx] , num , scsofar , MX)+score[arr[idx]];
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k ;
    cin >> n >>k ;
    for(int i = 1 ; i <=n ;i++)
    {
        cin >> arr[i];
    }
    for(int i = 1 ; i <=n ;i++)
    {
        cin >> score[i];
    }
    ll ans=OO , len , cyc;
    pair<int,int>p;
    for(int i = 1 ; i <=n ; i++)
    {
        memset(vis , 0 , sizeof vis);
        mx=OO;
        len=cycleLen(i);
        memset(vis , 0 , sizeof vis);
        cyc=cycleVal(i , 0 , 0 , k%len );
        ll x= k/len ;
        ans=max(ans , cyc*(x)+mx);
        memset(vis , 0 , sizeof vis);
        mx=OO;
        cyc=cycleVal(i , 0 , 0 , min(k,len) );
        ans=max(ans , cyc*max(x-1 , (long long)0)+mx);
        ans=max(ans , mx);
    }
    cout << ans ;
    return 0;
}
