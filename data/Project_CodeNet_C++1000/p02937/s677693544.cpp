#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define mp make_pair
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

vector<int> X[30];

int main(){
    string S, T;
    cin >> S >> T;

    ll NS, NT;
    NS = S.size();
    NT = T.size();

    REP(i,NS){
        int c = S[i] - 'a';
        X[c].push_back(i);
    }

    REP(i,NT){
        int c = T[i] - 'a';
        if(X[c].size() == 0){
            cout << -1 << endl;
            return 0;
        }
    }

    ll ans = 0;
    int pos = -1;
    REP(i,NT){
        int c = T[i] - 'a';
        auto iter = upper_bound(X[c].begin(), X[c].end(), pos);
        if(iter == X[c].end()){
            ans += NS;
            pos = X[c][0];
        }
        else{
            pos = *iter;
        }
    }

    ans += pos+1;
    cout << ans << endl;

    return 0;
}
