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

int n;
int main(){
    cin >> n;
    vector<int> p(n), q(n);
    rep(i, 0, n) cin >> p[i];
    rep(i, 0, n) cin >> q[i];

    vector<int> tp = p, tq = q;
    sort(ALL(tp)); sort(ALL(tq));
    int cp = 0, cq = 0;

    do{
        cp++;
        int same = 0;
        rep(i, 0, n) if(tp[i] == p[i]) same++;
        if(same == n) break;
    }while(next_permutation(ALL(tp)));

    do{
        cq++;
        int same = 0;
        rep(i, 0, n) if(tq[i] == q[i]) same++;
        if(same == n) break;
    }while(next_permutation(ALL(tq)));

    int ans = abs(cp - cq);
    cout << ans << endl;

    return 0;
}
