#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

int main(){
    int N;
    cin >> N;
    //num[i]:=iが何回登場するか、cnt[i]:=i回登場する数字が何個あるか
    int num[N], cnt[N+1];
    fill(num, num+N, 0), fill(cnt, cnt+N+1, 0);
    rep(i, N){
        int A; cin >> A; A--;
        num[A]++;
    }
    rep(i, N) cnt[num[i]]++;
    //sum1[i]:=cnt[0]+cnt[1]+...+cnt[i-1]、sum2[i]:=0*cnt[0]+1*cnt[1]+...+(i-1)*cnt[i-1]
    int sum1[N+2], sum2[N+2];
    sum1[0] = sum2[0] = 0;
    rep(i, N+1){
        sum1[i+1] = sum1[i]+cnt[i];
        sum2[i+1] = sum2[i]+(i*cnt[i]);
    }
    //lim[i]:=i回操作できる最大のK
    int lim[N+2];
    lim[0] = N, lim[N+1] = 0;
    rep2(i, 1, N){
        int all = sum2[i]+i*(N-sum1[i]);
        lim[i] = all/i;
    }
    rep3(i, N, 0){
        rep(j, lim[i]-lim[i+1]) cout << i << endl;
    }
}