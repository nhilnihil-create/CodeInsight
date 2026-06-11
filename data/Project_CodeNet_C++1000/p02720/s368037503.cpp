#include <bits/stdc++.h>

#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define pi 3.141592653
#define oo 1000000007
#define loo 10000000000000007

#define prime 1000000007

#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";
using namespace std;

int v[5050], u[5050];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    queue<ll> q;
    vl ans;
    for (ll i = 1; i < 10; ++i){
        q.push(i);
        ans.pb(i);
    }
    while((int)ans.size() < n){
        ll aux = q.front();
        q.pop();
        ll d = aux%10;
        ll at = 10*aux+d-1;
        if(d > 0){
            q.push(at);
            ans.pb(at);
        }
        at = 10*aux+d;
        q.push(at);
        ans.pb(at);
        if(d < 9){
            at = 10*aux+d+1;
            q.push(at);
            ans.pb(at);
        }
    }
    cout << ans[n-1] << endl;
    
    return 0;
}