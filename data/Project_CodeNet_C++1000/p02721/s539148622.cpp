#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define rep(i, n) for (ll (i) = 0; (i) < (n); (i)++)
#define For(i, a, n) for (ll (i) = (a); (i) < (n); (i)++)
#define prl(x) cout << (x) << endl
#define all(v) (v).begin(), (v).end()

int main(void){
    ll n,k,c;string s;cin>>n>>k>>c>>s;
    vector<vl> cnt(2,vl(n+1,0));
    auto func=[&](string& t,vl& cnt){
        ll res = 0;
        For(i,1,n+1){
            cnt[i]=cnt[i-1];
            if(!res&&t[i-1]!='x')cnt[i]++,res=c;
            else if(res)res--;
        }
    };
    func(s, cnt[0]);
    reverse(all(s));
    func(s, cnt[1]);
    rep(i,n)if(cnt[0][i]+cnt[1][n-1-i]<k)prl(i+1);
    return 0;
}