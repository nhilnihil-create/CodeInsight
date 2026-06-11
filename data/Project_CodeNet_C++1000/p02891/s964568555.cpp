#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    string s;
    ll n;
    cin >> s >> n;
    ll siz=s.size();
    vector<ll>cnt(siz,1);
    ll x=0;
    for(ll i=0;i<siz-1;i++){
        if(s[i]==s[i+1]){
            cnt[x]++;
        }
        else {
            x++;
        }
    }
    ll ans=0;
    for(ll i=0;i<siz;i++){
        ans+=cnt[i]/2;
    }
    for(ll i=siz-1;i>=0;i--){
        if(cnt[i]!=1){
            x=i;
            break;
        }
    }
    ans*=n;
    if(x==0){
        cout << siz*n/2 << endl;
        return 0;
    }
    if(s[0]==s[siz-1]){
        ans-=((cnt[0]/2)+(cnt[x]/2)-((cnt[0]+cnt[x])/2))*(n-1);
    }
    cout << ans << endl;
}