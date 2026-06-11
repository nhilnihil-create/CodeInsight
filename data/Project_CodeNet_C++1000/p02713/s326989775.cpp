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
#define endl '\n'
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
#define INF 1e9
#define DEBUG(x) cout<<"debug: "<<x<<endl
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}

int k;
ll ans;
int main(){
    cin >> k;
    rep(a, 1, k+1) rep(b, 1, k+1) rep(c, 1, k+1){
        ans += gcd(gcd(a, b), c);
    }
    cout << ans << endl;
    return 0;
}
