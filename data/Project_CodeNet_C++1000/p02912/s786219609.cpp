#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
#define mp make_pair
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl

using Graf_char=vector<vector<char>>;
using Graf_int=vector<vector<int>>;
#define MAX 10000000

int main()
{
    int n,m;
    cin >> n >> m;
    priority_queue<ll> q;
    ll a;
    rep(i,n){
        cin >> a;
        q.push(a);
    }
    rep(i,m){
        ll b=q.top();
        q.pop();
        b/=2;
        q.push(b);
    }
    ll ans=0;
    rep(i,n){
        ans+=q.top();
        q.pop();
    }
    cout << ans << endl;
}