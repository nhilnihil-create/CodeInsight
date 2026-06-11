#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <cstdint>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000000000
#define MAX 200001

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const ll MOD = 1000000007;

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

int main(){
    int N;
    cin >> N;
    vector<int> A(N),A_p,A_n;
    rep(i,N) cin >> A[i];
    sort(A.begin(), A.end());
    rep(i,N){
        if(A[i] <= 0) A_n.push_back(A[i]);
        else A_p.push_back(A[i]);
    }
    if(A_n.size() == 0){
        int now = A_p[0];
        int ans = 0;
        rep(i,N-1){
            ans += A_p[i+1];
        }
        cout << ans - A_p[0] << endl;
        rep(i,N-2){
            cout << now << ' ' << A_p[i+1] << endl;
            now -= A_p[i+1];
        }
        cout << A_p[N-1] << ' ' << now << endl;
    }
    else if(A_p.size() == 0){
        int ans = 0;
        int now = A_n[N-1];
        rep(i,N-1){
            ans += -A_n[i]; 
        }
        ans += A_n[N-1];
        cout << ans << endl;
        rep(i,N-1){
            cout << now << ' ' << A_n[i] << endl;
            now -= A_n[i];
        }
    }
    else{
        int ans = 0;
        for(auto n:A_n) ans += n*-1;
        for(auto p:A_p) ans += p;
        cout << ans << endl;
        int s_n = A_n.size();
        int s_p = A_p.size();
        if(s_p == 1){
            int now = A_p[0];
            for(auto n:A_n){
                cout << now << ' ' << n << endl;
                now -= n;
            }
        }
        else{
            cout << A_n[0] << ' ' << A_p[0] << endl;
            int now = A_n[0] - A_p[0];
            for(int i = 1; i < s_p-1; i++){
                cout << now << ' ' << A_p[i] << endl;
                now -= A_p[i];
            }
            cout << A_p[s_p-1] << ' ' << now << endl;
            now = A_p[s_p-1] - now;
            for(int i = 1; i < s_n; i++){
                cout << now << ' ' << A_n[i] << endl;
                now -= A_n[i];
            }
        }
    }
}