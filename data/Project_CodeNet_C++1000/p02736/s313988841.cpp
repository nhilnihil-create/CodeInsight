#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592
#define PI acos(-1.0);

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

int calc(int a){
    int res = 0;
    int now = 2;
    while(a >= now){
        res += a/now;
        now *= 2;
    }
    return res;
}


int main(){
    int N; cin >> N;
    string s; cin >> s;
    vector<int> a(N);
    rep(i,N) a[i] = s[i]-'0';
    bool ok = false;
    rep(i,N){
        a[i]--;
        if(a[i] == 1) ok = true;
    }
    if(!ok){
        rep(i,N) a[i] /= 2;
    }
    rep(i,N){
        if(a[i] == 2) a[i] = 0;
    }
    int ans = 0;
    rep(i,N){
        int cnt1 = calc(N-1);
        int cnt2 = calc(N-1-i);
        int cnt3 = calc(i);
        if(cnt1 == cnt2+cnt3){
            ans += a[i];
            ans %= 2;
        }
    }
    if(!ok) ans *= 2;
    cout << ans << endl;
}

