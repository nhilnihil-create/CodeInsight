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

char field[10][10];
bool grand[10][10] = {false};
bool reached[10][10] = {false};

int main() {
    int A, B;
    cin >> A >> B;

    int ans = 0, res = 1, pos = 0;
    while(1){
        if (res >= B){
            break;
        }
        res = res+A-1;
        ans++;
    }
    cout << ans << endl;
}