#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9+7
#define rep(i,n) for(ll i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
const int maxn = 200000;
ll mod = INF;

ll n;
ll a[maxn];
ll sum=0;
map<ll,ll> m;

int main(){
    cin >> n;
    rep(i,n){
        cin >> a[i];
        m[a[i]]++;
    }

    for(auto ite=m.begin();ite!=m.end();ite++){
        ll k=ite->second;
        sum+=k*(k-1)/2;
    }
    //cout << "sum="<<sum<<endl;
    rep(i,n){
        ll k=a[i];
        if(m[k]==1){
            cout << sum<<endl;
        }else if(m[k]==2){
            cout << sum-1<<endl;
        }else{
            cout << sum-(m[k]-1)<<endl;
        }
    }
    return 0;
}