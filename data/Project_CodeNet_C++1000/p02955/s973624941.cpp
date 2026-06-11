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

const double pi=3.141592653589793;
const ll MOD=1e9+7;

vector< int64_t > divisor(int64_t n) {
    vector< int64_t > ret;
    for(int64_t i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
sort(begin(ret), end(ret));
return (ret);
}

int main() {
    ll n,k;
    cin>>n>>k;
    ll a[n];
    ll s=0;
    rep(i,n){
        cin>>a[i];
        s+=a[i];
    }
    //aの合計sは一定,sの約数が答えの候補
    auto d=divisor(s);
    ll ans=1;
    for (int x:d){
        //ll c=0;
        vll rl;
        rep(i,n){
            rl.push_back(a[i]%x);
        }
        sort(all(rl));
        ll right=n-1,left=0;
        ll c=0;
        ll now=0;
        while(left<right || now>0){
            if (now==0){
                now+=rl[left];
                left+=1;
            }
            if (now+rl[right]>x){
                now-=(x-rl[right]);
                c+=x-rl[right];
                right-=1;
            }
            else{
                rl[right]+=now;
                c+=now;
                now=0;
            }
        }
        if (c<=k){
            ans=x;
        }

    }
    cout<<ans<<endl;

    return 0;
}