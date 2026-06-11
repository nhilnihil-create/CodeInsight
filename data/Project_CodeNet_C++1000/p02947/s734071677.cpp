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

ll calcNumOfCombination(ll n, ll r){
        ll num = 1;
        for(ll i = 1; i <= r; i++){
            num = num * (n - i + 1) / i;
        }
        return num;
    }

int main() {
    int N;
    cin >> N;

    string S[N];
    map<string, int> mp{};
    REP(i, N){
        cin >> S[i];
        sort(S[i].begin(), S[i].end());
        mp[S[i]]++;
    }

    ll ans = 0;
    auto begin = mp.begin(), end = mp.end();
    for (auto iter = begin; iter != end; iter++) {
        int x = mp[iter->first];

        ans += calcNumOfCombination(x, 2);
    }
    cout << ans << endl;
}