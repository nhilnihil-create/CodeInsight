#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> lP;
const ll mod = 1000000007;
const ll INF = 1e+14;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG

int main(){
    int n; cin>>n;
    vector<lP> schedule;

    rep(i,n){
        ll x,l;
        cin>>x>>l;
        ll pre=x-l;
        ll aft=x+l;
        P robo={aft,pre};
        schedule.push_back(robo);
    }

    sort(schedule.begin(),schedule.end());

    ll ans=0;
    ll t=-INF; //tは最後に選んだ仕事の終了時刻
    rep(i,n){
        if(schedule[i].second>=t){
            ans++;
            t=schedule[i].first;
        }
    }
    
    cout<<ans<<endl;
}