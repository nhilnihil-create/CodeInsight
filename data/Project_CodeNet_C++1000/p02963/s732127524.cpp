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
    ll s; cin >> s;
    ll div = 1e9;
    ll y2 = (s + div - 1) / div;
    ll y1 = div * y2 - s;
    cout << 0 << " " << 0 << " " << div << " " << y1 << " " << 1 << " " << y2 << endl;
}