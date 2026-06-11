#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int N;
    cin >> N;
    ll A[N];
    vector<int> p, z, n;
    rep(i, N){
        cin >> A[i];
        if(A[i] > 0) p.pb(A[i]);
        elif(A[i] == 0) z.pb(A[i]);
        else n.pb(A[i]);
    }
    ll sum = 0;
    rep(i, N) sum += abs(A[i]);
    if(!n.empty() && !p.empty()){
        cout << sum << endl;
        ll now1 = n[n.size()-1];
        rep(i, p.size()-1){
            cout << now1 << ' ' << p[i] << endl;
            now1 -= p[i];
        }
        ll now2 = p[p.size()-1];
        rep(i, n.size()-1){
            cout << now2 << ' ' << n[i] << endl;
            now2 -= n[i];
        }
        cout << now2 << ' ' << now1 << endl;
        rep(i, z.size()){
            cout << sum << ' ' << 0 << endl;
        }
    }
    elif(n.empty()){
        sort(A, A+N);
        cout << sum-2*A[0] << endl;
        ll now = A[0];
        rep2(i, 1, N-2){
            cout << now << ' ' << A[i] << endl;;
            now -= A[i];
        }
        cout << A[N-1] << ' ' << now << endl;
    }
    else{
        sort(A, A+N, greater<ll>());
        cout << sum+2*A[0] << endl;
        ll now = A[0];
        rep2(i, 1, N-1){
            cout << now << ' ' << A[i] << endl;
            now -= A[i];
        }
    }
}