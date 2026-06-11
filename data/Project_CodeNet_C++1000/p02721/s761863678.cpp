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

ll N, K, C;
int scheduling(string X, vector<ll>& vec){
    int last = -1000;
    int idx = 0;
    REP(i,N){
        if(idx == K) break;
        char c = X[i];
        if(c == 'o' && i - last > C){
            vec[i] = idx++;
            last = i;
        }
        else
            vec[i] = -1;
    }

    return idx;
}

int main(){
    cin >> N >> K >> C;
    string S;
    cin >> S;

    //vector<ll> asap(N, 1e8);
    //vector<ll> alap(N, 1e10);
    vector<ll> asap(N, -1);
    vector<ll> alap(N, -1);

    int total;
    total = scheduling(S, asap);
    reverse(S.begin(), S.end());
    scheduling(S, alap);
    reverse(alap.begin(), alap.end());

    for(auto&& x : alap){
        if(x == -1) continue;
        x = total - x - 1;
    }


    //REP(i,N)
    //    printf("%+lld, ", asap[i]);
    //printf("\n");

    //REP(i,N)
    //    printf("%+lld, ", alap[i]);
    //printf("\n");

    REP(i,N){
        if(asap[i] == -1) continue;
        if(alap[i] == -1) continue;
        if(asap[i] == alap[i])
            cout << i+1 << endl;
    }
    return 0;
}
