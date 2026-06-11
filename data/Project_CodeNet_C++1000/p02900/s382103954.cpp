#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef vector<int> V;
typedef pair<int,int> P;
typedef vector<vector<int>> Graph;

int main() {
    ll a,b;
    cin >> a >> b;
    map<ll,ll> fa,ck;
    ll n=a,m=b;
    for(ll i=2;i<=sqrt(a);i++){
        while(n%i==0){
            n /= i;
            fa[i]++;
        }
    }
    fa[1]++;
    fa[n]++;
    for(ll i=2;i<=sqrt(b);i++){
        while(m%i==0){
            m /= i;
            ck[i]++;
        }
    }
    ck[1]++;
    ck[m]++;
    ll ans=0;
    for(auto i:fa){
        if(ck[i.first]!=0) ans++;
    }
    cout << ans << endl;
}