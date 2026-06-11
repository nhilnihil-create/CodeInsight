#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 998244353;
using ll = long long;
using P = pair<ll, ll>;
double PI = acos(-1);

signed main(){
    int n,p;
    cin >> n>>p;
    string str;
    cin >> str;
    vector<int> x(n+1,0);
    if(p%2==0 || p%5==0) {
        int ans = 0;
        rep(i,n) {
            x[i]=(int)(str[i]-'0')%p;
            if(x[i]%p==0) ans+=i+1;
        }
        cout << ans << endl;
        return 0;
    }

    x[n]= 1;
    rrep(i,n) {
        x[i]= x[i+1]*10%p;
        //cout << x[i] << endl;
    }
    rrep(i,n) {
        x[i]*= (int)(str[i]-'0');
        //cout << x[i] << endl;
        x[i] %= p;
        // x[i] +=x[i+1];
        // x[i] %= p;
        //cout << x[i] << endl;
    }
    int ans = 0;
    vector<int> sum(n+1,0);
    sum[n] = 0;
    
    map<int, int> ma;
    rrep(i,n) {
        sum[i] = (sum[i+1]+x[i])%p;        
        ma[sum[i]]++;
    }

    ma[0]++;
    for(auto num:ma) {
        //cout << num.first<<" " <<num.second << endl;
        ans += (num.second)*(num.second-1)/2;
    }
    cout << ans << endl;

    return 0;
}

