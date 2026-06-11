#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
    int N;
    cin>>N;
    vector<pair<ll, ll> > robots(N);
    int x, l;
    for(int i=0;i<N;++i){
        cin>>x>>l;
        robots[i] = mp(x+l, x);
    }
    sort(robots.begin(), robots.end());
    int ans = 0;
    ll tmp = robots[0].fi;
    for(int i=1;i<N;++i){
        if(tmp > 2 * robots[i].se - robots[i].fi){
            ans++;
        }
        else{
            tmp = robots[i].fi;
        }
    }
    cout<<N-ans<<endl;
}

