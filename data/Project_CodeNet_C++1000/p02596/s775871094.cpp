//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define repp(i,n,s) for (int i= (int)(n); i >= (int)(s); i--)
#define mp make_pair
ll mod = 1000000007;
ll mod2 = 998244353;

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    ll k;cin>>k;
    ll s = 7;
    ll m = k;
    ll cnt = 0;
    map<pair<ll,ll>,int> al;
    while (true){
        cnt++;
        s %= k;
        m = (m+s)%k;
        
        if (al[mp(m,s)]==1){
            cout<<-1<<endl;
            return 0;
        }
        al[mp(m,s)] = 1;
        if (m%k==0) break;
        s *= 10;
    }
    cout<<cnt<<endl;
}