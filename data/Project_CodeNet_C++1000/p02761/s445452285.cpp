#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
using ll=long long;
using P=pair<int,int>;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define el '\n'
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
#define INF 1e9
#define DEBUG(x) cout<<"debug: "<<x<<endl
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

int n, m, ans = INF;
vector<P> sc(5);
int main(){
    cin >> n >> m;
    rep(i, 0, m) cin >> sc[i].first >> sc[i].second;

    int start = pow(10, n-1); if(start < 10) start = 0;
    int end = pow(10, n);

    rep(i, start, end){
        int cnt = 0;
        string str = to_string(i);
        rep(i, 0, m){
            int f = sc[i].first, s = sc[i].second;
            f--;
            if(str[f]-'0' == s) cnt++;
        }
        if(cnt == m){
            ans = i;
            break;
        }
    }

    if(ans == INF) cout << -1 << el;
    else cout << ans << el;

    return 0;
}
