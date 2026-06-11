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
    string S;
    cin >> S;

    char a = S[0], res = 0;
    bool flag = true;
    REP(i, 4){
        res = 0;
        REP(j, 4){
            if (S[i] == S[j]) res++;
        }
        if (res != 2) flag = false;
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}