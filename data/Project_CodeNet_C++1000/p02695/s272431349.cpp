#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

int n,m,q;
vector<int> a,b,c,d;
int ans = 0;

void dfs(vector<int> v){
    if(v.size() == n){
        int now = 0;
        rep(i,q){
            if(v[b[i]]-v[a[i]] == c[i]){
                now += d[i];
            } 
        }
        ans = max(ans,now);
        return;
    }
    if(v.size() == 0){
        repr(i,1,m+1){
            v.push_back(i);
            dfs(v);
            v.pop_back();
        }
    }
    else{
        int k = v.size();
        int d = v[k-1];
        repr(i,d,m+1){
            v.push_back(i);
            dfs(v);
            v.pop_back();
        }
    }
}

int main(){
    cin >> n >> m >> q;
    a.resize(q);
    b.resize(q);
    c.resize(q);
    d.resize(q);
    rep(i,q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--;
        b[i]--;
    }
    vector<int> v;
    dfs(v);
    cout << ans << endl;
}

