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
    int N;
    string S;

    cin >> N >> S;

    bool flag = true;
    if(N%2 == 0){
        REP(i, N/2){
            if (S[i] != S[N/2+i]) {
                flag = false;
                break;
            }
        }
    }
    else flag = false;

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}