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

void dfs(int d,ll num,vector<ll> &lunlun){
    lunlun.push_back(num);
    if(d == 10) return;

    for (int i = -1; i <= 1; ++i) {
        int tmp = num%10;
        tmp += i;
        if(tmp >= 0 && tmp <= 9){
            dfs(d+1,10*num+tmp,lunlun);
        }
    }
}

int main() {
    int k;
    cin >> k;
    vector<ll> ans;
    for (int i = 1; i <= 9; ++i) {
        dfs(1,i,ans);
    }
    sort(ans.begin(),ans.end());
    cout << ans[k-1] << endl;
    return 0;
}