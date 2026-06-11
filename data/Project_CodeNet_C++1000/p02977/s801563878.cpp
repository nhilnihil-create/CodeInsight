#include <bits/stdc++.h>
#define owo(i,a, b) for(int i=(a);i<(b); ++i)
#define uwu(i,a, b) for(int i=(a)-1; i>=(b); --i)
#define senpai push_back
#define ttgl pair<int, int>
#define ayaya cout<<"ayaya~"<<endl
 
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
gp_hash_table<int, int> mp;*/
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;
const ll root = 62;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
ll binpow(ll a,ll b){ll res=1;while(b){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;b>>=1;}return res;}
ll modInv(ll a){return binpow(a, MOD-2);}
const double PI = acos(-1);
const double eps = -1e6;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll NINFLL = 0xc0c0c0c0c0c0c0c0;
const int mxN = 100001;
vector<ttgl> ans;
bool one[mxN];
int two[20];
int n;
int main() {
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    two[0] = 1;
    owo(i, 1, 20) {
        two[i] = two[i-1]*2;
    }
    owo(i, 0, 20) {
        if(n==two[i]) {
            cout<<"No\n";
            exit(0);
        }
    }
    ans.senpai({1, 2});
    one[2] = true;
    ans.senpai({2, 3});
    ans.senpai({3, 1+n});
    ans.senpai({1+n, 2+n});
    ans.senpai({2+n, 3+n});
    for(int i=4; i<n; i+=2) {
        ans.senpai({1, i});
        one[i] = true;
        ans.senpai({i, i+1});
        ans.senpai({1, i+n+1});
        ans.senpai({i+n+1, i+n});
    }
    cout<<"Yes\n";
    if((n&1)==0) {
        int k = n-1;
        int lowest = 0;
        while(k&(two[lowest]))lowest++;
        int add = two[lowest];
        if(one[n-add+1]) {
            ans.senpai({n, n-add+1});
        }else {
            ans.senpai({n, n-add+1+n});
        }
        if(one[add]) {
            ans.senpai({n+n, add});
        }else {
            ans.senpai({n+n, add+n});
        }
    }
    for(auto p: ans) {
        cout<<p.first<<" "<<p.second<<"\n";
    }
    return 0;
}
