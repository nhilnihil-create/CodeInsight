#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);


int main(void)
{
    ll k,x,ans=1; cin>>k;
    x=7%k;
    set<ll> s;
    while(s.count(x)==0){ //訪れてない限り続ける
        if(x==0){
            cout << ans << endl;
            return 0;
        }
        s.insert(x);
        x = (x*10+7)%k;
        ans++;
    }
    cout<<-1<<endl;
    return 0;
}