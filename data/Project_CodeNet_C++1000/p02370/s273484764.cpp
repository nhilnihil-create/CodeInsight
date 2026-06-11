#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <functional>

using namespace std;

#define fst first
#define scd second
#define PB push_back
#define MP make_pair
#define rep(i,x) for(int i=0;i<(x);++i)
#define rep1(i,x) for(int i=1;i<=(x);++i)
#define rrep(i,x) for(int i=(x)-1;i>=0;--i)
#define rrep1(i,x) for(int i=(x);i>=1;--i)
#define int long long
#define FOR(i,a,x) for(int i=(a);i<(x);++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define omajinai ios::sync_with_stdio(false);cin.tie(0)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

template<typename T>T& max(T&a,T&b){if(a>=b)return a;return b;}
template<typename T>T& min(T&a,T&b){if(a<b)return a;return b;}
template<typename T>bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<typename T>T get(){T a;cin>>a;return a;}
template<typename T>T rev(T a){reverse(all(a));return a;}
template<typename T>istream&operator>>(istream&is,vector<T>&vec){rep(i,vec.size())is>>vec[i];return is;}
template<typename T>vector<T>&sort(vector<T>&a){sort(all(a));return a;}

const int inf = 1e9;
const ll linf = 3e18;
const double eps = 1e-9;

vi G[10001];
int in[10001];

signed main()
{
    int V, E; cin >> V >> E;

    for (int i = 0; i < E; ++i) {
        int s, t; cin >> s >> t;

        G[s].PB(t);
        in[t]++;
    }

    vi ans;

    queue<int> St;

    for (int i = 0; i < V; ++i) {
        if (in[i] == 0) St.push(i);
    }

    while (St.size()) {
        int st = St.front(); St.pop();

        ans.push_back(st);

        for (int v : G[st]) {
            in[v]--;

            if (in[v] == 0) St.push(v);
        }
    }

    for (int a : ans) cout << a << endl;
}