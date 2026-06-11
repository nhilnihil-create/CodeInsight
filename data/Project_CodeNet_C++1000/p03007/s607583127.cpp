#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e5+5;
ll n,a[N];
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    cin>>n;
    for(ll i=0;i<n;i++)cin>>a[i];
    sort(a,a+n,greater<ll>());
    vector< pair<ll,ll> > ans;
    for(ll i=1;i<n-1;i++){
        if(a[i]>=0)ans.push_back({a[n-1],a[i]}),a[n-1]-=a[i];
        else ans.push_back({a[0],a[i]}),a[0]-=a[i];
    }
    ans.push_back({a[0],a[n-1]});
    cout<<a[0]-a[n-1]<<"\n";
    for(auto &ele:ans)cout<<ele.first<<" "<<ele.second<<"\n";
}