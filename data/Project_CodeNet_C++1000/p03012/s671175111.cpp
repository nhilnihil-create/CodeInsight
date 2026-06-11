#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int N = 1000000;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}

/*------------------------------------------------------------------*/


int main(){
    int n; cin >> n;
    vector<int> w(n);
    rep(i, n) cin >> w[i];
    int s1 = 0, s2 = 0;
    int dif_min = 1000000;
    rep(i, n) s2 += w[i];
    rep(i, n){
        s1 += w[i];
        s2 -= w[i];
        dif_min = min(abs(s2 - s1), dif_min);
    }
    cout << dif_min << endl;
}