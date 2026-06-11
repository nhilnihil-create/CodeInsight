#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007,mod2 = 998244353;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL<<60;
ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

bool is_prime[1000010];

int main() {
    int n;
    cin >> n;
    vector<int> p(n),q(n),tmp(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
    }
    for (int i = 1; i <= n; ++i) {
        tmp[i-1] = i;
    }
    int cnt = 0,ansp,ansq;
    do{
        if(p == tmp){
            ansp = cnt;
        }
        cnt++;
    }while(next_permutation(tmp.begin(),tmp.end()));
    sort(tmp.begin(),tmp.end());
    cnt = 0;
    do{
        if(q == tmp){
            ansq = cnt;
        }
        cnt++;
    }while(next_permutation(tmp.begin(),tmp.end()));
    cout << abs(ansp-ansq) << endl;
    return 0;
}