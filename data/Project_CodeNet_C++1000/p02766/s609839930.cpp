#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;

    vector<ll> ans;
    ll i = 0, res = N%K, pos = N/K;
    while (pos != 0){
        ans.push_back(res);
        res = pos%K;
        pos = pos/K;
    }
    ans.push_back(res);

    cout << SIZE(ans) << endl;
}