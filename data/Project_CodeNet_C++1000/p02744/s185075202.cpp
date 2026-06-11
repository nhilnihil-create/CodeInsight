#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define ALL(a) (a).begin(),(a).end()
 
using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
 
const ll MOD  = 1e9+7;
const ll LINF = 1LL << 60;
const int INF = 1e9 + 7;

map<string, int> ans;
bool used[10] = {};
int n;

void dfs(string s, ll mx){
    if(s.size() == n)ans[s] = 1;
    else {
        rep(i, mx+2){
            dfs(s+char('a'+i), max(mx, i));
        }
    }
}

int main(){
    cin >> n;

    dfs("a", 0);

    for(auto itr = ans.begin(); itr != ans.end();itr++){
        cout << itr->first << endl;
    }
}