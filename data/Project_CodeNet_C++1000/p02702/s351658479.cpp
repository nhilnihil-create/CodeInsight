#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    string s;
    cin>>s;
    reverse(all(s));

    int n=s.size();
    vector<ll> cnt(2019,0);

    cnt[0]++;
    ll x=1;
    ll tmp=0;
    rep(i,n){
        tmp=(tmp+((s[i]-'0')*x)%2019)%2019;
        cnt[tmp]++;
        //cout<<tmp<<endl;
        x=(x*10)%2019;
    }

    ll ans=0;
    rep(i,2019){
        ans+=cnt[i]*(cnt[i]-1)/2;
    }

    cout<<ans<<endl;
}