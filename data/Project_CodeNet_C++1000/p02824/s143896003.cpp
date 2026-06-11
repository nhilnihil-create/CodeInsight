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

ll N, M, V, P;
vector<ll> A;

bool search(int idx){
    int free = (P-1) + (N-idx);
    int rem = V - free;
    ll sup = A[idx] + M;
    if(sup < A[P-1])
        return false;
    ll num = rem * M;

    for(int i = P-1; i < idx; i++){
        ll a = A[i];
        ll sub = 0;
        chmax(sub, min(M, sup - a));
        num -= sub;
    }

    if(num <= 0) return true;
    else return false;
}

int main(){
    cin >> N >> M >> V >> P;
    A.resize(N);
    REP(i,N){
        cin >> A[i];
    }

    sort(A.rbegin(), A.rend());

    ll ans = 0;

    int left = 0;
    int right = N;
    //int left = 6;
    //int right = 8;
    while(right - left > 1){
        int mid = (left+right)/2;
        bool valid = search(mid);
        if(valid) left = mid;
        else right = mid;
    }

    ans = left+1;
    cout << ans << endl;
    return 0;
}
