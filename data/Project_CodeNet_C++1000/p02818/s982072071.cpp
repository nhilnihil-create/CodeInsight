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
    ll A, B, K;
    cin >> A >> B >> K;

    ll ans_a = 0, ans_b = 0;
    if (A-K < 0){
        ans_a = 0;
        if (B - K + A < 0){
            ans_b = 0;
        }
        else{
            ans_b = B - K + A;
        }
    }
    else{
        ans_a = A - K;
        ans_b = B;
    }

    cout << ans_a << " " << ans_b << endl;
}