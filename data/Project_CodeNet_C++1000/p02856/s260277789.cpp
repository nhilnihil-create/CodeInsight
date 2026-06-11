#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=acos(-1);
const ll MOD=1e9+7;

int main() {
    int m;
    cin>>m;
    ll k=0,s=0;
    //桁数と桁和
    ll d,c;
    rep(i,m){
        cin>>d>>c;
        k+=c;
        s+=d*c;
    }
    ll ans=k-1+(s-1)/9;
    cout<<ans<<endl;
    return 0;
}