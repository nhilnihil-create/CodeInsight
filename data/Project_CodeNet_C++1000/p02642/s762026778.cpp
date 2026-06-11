#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<string>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define reps(i,n) for(int i=1;i<=(int)n;i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define LB(a,x) lb(all(a), x) - a.begin()
#define UB(a,x) ub(all(a), x) - a.begin()
#define MOD 1000000007
#define itn int
#define enld endl
using namespace std;
typedef long long ll;
const double pi = 3.141592653589793;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b){if(b<a){a=b; return 1;} return 0;}
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    bool flag[1001001]; // A_iの中に自分を割り切る数が存在すればfalse
    Fill(flag,true);
    int N; cin >> N;
    int A[200200];
    int cnt[1001001];
    Fill(cnt ,0);
    rep(i,N){
        cin >> A[i];
        cnt[A[i]]++;
    }
    rep(i,N){
        if(flag[A[i]] == false) continue;

        if(cnt[A[i]] > 1) flag[A[i]] = false; // 同じ数が2回以上登場すると割り切れるのでfalse
        for(int j=A[i]*2;j<=1000000;j+=A[i]) flag[j] = false; // A[i]のA[i]自身を除く倍数は全てfalse
    }

    int ans = 0;
    rep(i,N){
        if(flag[A[i]] == true) ans++;
    }
    cout << ans << enld;
    return 0;
}