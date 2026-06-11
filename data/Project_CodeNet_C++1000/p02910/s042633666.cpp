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
    char Odd[3] = {'R', 'U', 'D'};
    char Eve[3] = {'L', 'U', 'D'};

    string S;
    cin >> S;

    bool flag;
    REP(i, S.length()){
        flag = false;
        if (i%2 == 0) {
            REP(j, 3){
                if (S[i] == Odd[j]) flag = true;
            }
        }
        else {
            REP(j, 3){
                if (S[i] == Eve[j]) flag = true;
            }
        }

        if(flag == false) break;
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}