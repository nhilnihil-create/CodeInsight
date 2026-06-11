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
typedef pair<int, int> P;

P fin(int n){
    int a, b;
    a = n%10;

    while(n){
        b = n;
        n /= 10;
    }
    return P(a, b);
}

int main() {
    int N;
    cin >> N;

    map<P, int> mp;
    FOR(i, 1, N){
        P p = fin(i);
        mp[p]++;
    }
    
    int ans = 0;
    FOR(i, 1, N){
        P p = fin(i);
        P q(p.second, p.first);
        ans += mp[q];
    }
    cout << ans << endl;
}