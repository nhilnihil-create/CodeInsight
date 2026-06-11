//AGC041-B
//二分探索の応用

#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define rep(i, n) for(int i=0; i<n; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define V(T) vector<T>
//typedef pair<int, int> P;
//typedef pair<P, P> PP;
typedef vector<int> vi;
typedef vector<vi> vvi;
int max(int a, int b) {if(b>a) return b; else return a;}
int min(int a, int b) {if(b<a) return b; else return a;}
const int INF = 1e18;

int N, M, V, P;

bool ok(int n, vi &A) {
    if(n<P) return true;
    if(A[P-1] > A[n]+M) return false;
    int sum = 0;
    sum += M*(P-1); sum+=M*(N-n);
    FOR(i, P-1, n) {
        sum += min(M, max(0, A[n]+M-A[i]));
    }
    return sum>=M*V;
}

signed main() {
    cin >> N >> M >> V >> P;
    vi A(N);
    rep(i, N) {
        cin >> A[i];
    }
    GSORT(A);

    int l=-1, r=N, mid;
    while(abs(l-r)>1) {
        mid = (l+r)/2;
        if(ok(mid, A)) l=mid;
        else r = mid;
    }

    cout << l+1 << endl;
    
    return 0;
}