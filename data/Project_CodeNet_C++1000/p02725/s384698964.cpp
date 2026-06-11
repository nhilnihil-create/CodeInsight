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

int k, n;
int main(){
    cin >> k >> n;
    vector<int> a(n);
    cin >> a[0];
    rep(i, 1, n){
        int t; cin >> t;
        a[i] = t - a[0];
    }
    a.push_back(k);

    int maxl = 0;
    rep(i, 0, n){
        maxl = max(maxl, a[i+1]-a[i]);
    }

    cout << k - maxl << endl;

    return 0;
}
