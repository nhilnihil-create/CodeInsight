#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

vector<pair<long long, long long> > prime_factorize(long long n) {
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

int main(){
    ll n;
    cin>>n;

    auto pf=prime_factorize(n);
    ll ans=0;
    for(auto p : pf){
        int x=p.second;
        int cnt=1;
        //cout<<x<<endl;
        while(true){
            ans++;
            cnt++;
            x-=cnt;
            if(x<=0) break;
        }
    }

    cout<<ans<<endl;
}