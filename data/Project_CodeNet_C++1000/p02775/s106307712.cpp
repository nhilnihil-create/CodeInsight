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

int main(){
    string S;
    cin >> S;

    reverse(S.begin(), S.end());
    S += '0';
    ll N = S.size();

    ll ans = 0;
    vector<ll> add(N+100, 0);
    REP(i,N){
        int x = S[i] - '0';
        x += add[i];
        if(x > 5){
            x = 10 - x;
            add[i+1]++;
        }
        else if(x == 5){
            int next = S[i+1] - '0';
            if(next > 4){
                x = 10 - x;
                add[i+1]++;
            }
        }
        //S[i] = x + '0';
        ans += x;
    }

    cout << ans << endl;
    return 0;
}
