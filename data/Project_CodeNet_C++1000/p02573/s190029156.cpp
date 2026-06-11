#include <bits/stdc++.h>

using namespace std;

#define Fast  ios::sync_with_stdio(false); cin.tie(0)
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define S second
#define F first
typedef long long ll;
const ll mod = 1e9 + 7;
const ll N = 2e5 + 5;
ll inf = 1e18;
ll tmp = 0;

vector <ll> vec[N];
pair <ll ,ll> p[N];
bool vst[N];

void dfs(int v){
    vst[v] = true;
    tmp ++;
    for(int i = 0 ; i < vec[v].size(); i ++){
        if(!vst[vec[v][i]]){
            dfs(vec[v][i]);
        }
    }
}

int main(){

    Fast;

    int n , m;
    cin >> n >> m;

    for(int i = 0 ; i < m; i ++){
        cin >> p[i].F >> p[i].S;
    }
    sort(p , p + m);

    int x = p[0].F , y = p[0].S;
    vec[p[0].F].pb(p[0].S);
    vec[p[0].S].pb(p[0].F);

    for(int i = 1; i < m ;i ++){
        if((x == p[i].F && y == p[i].S) || (x == p[i].S && y == p[i].F));
        else{
            x = p[i].F;
            y = p[i].S;
            vec[x].pb(y);
            vec[y].pb(x);
        }
    }

    ll ans = 0;

    for(int i = 1; i <= n ;i ++){
        if(!vst[i]){
            dfs(i);
            ans = max(ans , tmp);
            tmp = 0;
        }
    }

    cout << ans << endl;



    return 0;
}
