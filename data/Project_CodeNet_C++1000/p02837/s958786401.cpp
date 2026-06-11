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
#define rep(i,n,m) for(int i=(n);i<(int)(m);i++)
#define reps(i,n,m) for(int i=(n);i<=(int)(m);i++)
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
#define icn cin
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
    int N; cin >> N;
    int isHonest[20];
    int A[20];
    int x[20][20];
    int y[20][20];
    rep(i,0,N){
        cin >> A[i];
        rep(j,0,A[i]){
            int a,b; cin >> a >> b;
            a--;
            x[i][j] = a;
            y[i][j] = b;
        }
    }

    int ans = 0;
    rep(i,0,1<<N){
        int cnt = 0;
        rep(j,0,N){
            if(i & (1 << j)){
                isHonest[j] = 1;
                cnt++;
            }else{
                isHonest[j] = 0;
            }
        }
        bool flag = true;
        rep(k,0,N){
            if(isHonest[k] == 0) continue;
            rep(l,0,A[k]){
                if(isHonest[x[k][l]] != y[k][l]) flag = false;
            }
        }
        if(flag){
            ans = max(ans, cnt);
        }
    }

    cout << ans << endl;
}