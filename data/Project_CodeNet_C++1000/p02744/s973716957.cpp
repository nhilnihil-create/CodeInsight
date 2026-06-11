#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <numeric>
#include <iomanip>
#define ll long long
#define pi 3.14159265358979323846
using namespace std;
using p = pair<ll, ll>;
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};
/*
 vector<vector<ll>> g(n+1);
    for(ll i = 0; i < m; i++){
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<ll> dist(n+1, -1);
    queue<ll> que;
    que.push(1);
    dist[1] = 0;
    while(!que.empty()){
        ll v = que.front();
        que.pop();
        for(ll nv : g[v]){
            if(dist[nv]!=-1) continue;
            dist[nv] = dist[v]+1;
            que.push(nv);
        }
    }
*/
ll n;
vector<string> ans;
string c = "abcdefghijk";
void func(string s){
    ll MAX = 0;
    for(ll i = 0; i < n; i++){
        char a = s[i];
        ll b = a-96;
        MAX = max(MAX, b);
    }
    if(s.length()<n){
        for(ll i = 0; i <= MAX; i++){
            string t = s+c[i];
            func(t);
        }
    }
    if(s.length()==n)
        ans.push_back(s);
}
int main(){
    cin >> n;
    string t = "a";
    func(t);
    for(ll i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}
