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

int main() {
    ll A, B, K;
    cin >> A >> B >> K;

    ll t = 0, a = 0; 
    if(A - K <= 0){
         t = 0;
         if (K - A >= B){
             a = 0;
         }
         else a = B - (K - A);
    }
    else{
        t = A - K;
        a = B;
    }
    
    cout << t << " " << a << endl;
}