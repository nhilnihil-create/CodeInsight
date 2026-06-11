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

vector<pair<ll,int>> factorize(ll n){
    vector<pair<ll,int>> div;
    ll d = n;
    for(ll i = 2; i*i <= n; i++){
        pair<ll,int> p;
        if(d % i == 0){
            p = make_pair(i,0);
            while(d % i == 0){
                d /= i;
                p.second++;
            }
            div.emplace_back(p);
        }
    }
    if(d != 1) div.emplace_back(d,1);
    return div;
}

int main(){
    ll n; cin >> n;
    vector<pair<ll,int>> div = factorize(n);
    int ans = 0;
    rep(i,div.size()){
        int now = 1;
        while(div[i].second >= now){
            div[i].second -= now;
            now++;
            ans++;
        }
    }
    cout << ans << endl;
}

