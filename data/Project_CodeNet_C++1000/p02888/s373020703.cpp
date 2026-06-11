#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>; 
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1001001001001001001;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n; cin >> n;
    vector<ll> A(n); rep(i, n) cin >> A[i];
    sort(all(A));
    ll res = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            //left < c < right
            int a = A[i], b = A[j];
            int l= max(a-b, b-a), r = a+b;
            int left = upper_bound(all(A), l) - A.begin();
            int right = lower_bound(all(A), r) - A.begin(); 
            res += right - left;
            if(l < a && a < r)res--;
            if(l < b && b < r)res--;
        }
    }
    cout << res / 3 << ln;
}
    
