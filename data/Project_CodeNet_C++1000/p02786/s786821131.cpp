#include <bits/stdc++.h>
#define inf 1000000005
#define mod 1000000007
#define eps 1e-10
#define rep(i,n) for(int i = 0; i < (n); ++i) 
#define rrep(i,n) for(int i = 1; i <= (n); ++i) 
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define each(a,b) for(auto& (a): (b)) 
#define all(v) (v).begin(),(v).end() 
#define sz(v) (int)(v).size() 
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define mx(x,y) x=max(x,y) 
#define mn(x,y) x=min(x,y)
#define rev(v) reverse((v).begin(),(v).end());
#define so(v) sort((v).begin(), (v).end());
#define yn {puts("Yes");}else{puts("No");}
#define fi first
#define se second
#define pb push_back

using namespace std;

using ll = long long;
using P = pair<int,int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vd = vector<double>;
using vp = vector<P>;
using vs = vector<string>; 

int main() {
    unsigned long long h;
  	ll ct,t;
    cin >> h;
  	ct=0;
    vl k;
    k.pb(1) ;
    rep(i, 100) {
        t = k.at(i);
        k.pb(2*t);
    }
    t = 0;
    while (h >= 1) {
        ct = ct + k.at(t);
        t++;
        h = h / 2;
    }
    cout << ct << endl;
    return 0;
}
