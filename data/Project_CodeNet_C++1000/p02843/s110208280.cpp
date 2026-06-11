#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);


int main(void)
{
    ll x; cin>>x;
    for(int i=1;i<=1000;i++){
        if(100*i<=x && x<=105*i){
            cout<<1<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}