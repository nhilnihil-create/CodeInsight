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
    ll N;
    cin >> N;
    vector<queue<ll>> A(N);
    REP(i,N){
        REP(j,N-1){
            ll a;
            cin >> a;
            a--;
            A[i].push(a);
        }
    }

    ll ans = 0;
    set<ll> candidate;
    REP(i,N) candidate.insert(i);
    while(1){

        vector<bool> assign(N);

        set<ll> next;
        //for(int v = 0; v < N; v++){
        for(auto&& v : candidate){
            if(assign[v]) continue;
            if(A[v].empty()) continue;

            ll x = A[v].front();
            if(assign[x]) continue;
            if(A[x].empty()){
                cout << -1 << endl;
                return 0;
            }

            ll y = A[x].front();

            if(v == y){
                A[v].pop();
                A[x].pop();
                assign[v] = true;
                assign[x] = true;
                next.insert(v);
                next.insert(x);
            }
        }

        candidate = next;

        if(candidate.size() == 0)
            break;

        ans++;
    }

    bool empty = true;
    REP(i,N){
        if(!A[i].empty())
            empty = false;
    }

    if(empty)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}
