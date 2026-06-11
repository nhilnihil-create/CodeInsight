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
#define printfdouble(x) printf("%.12f\n",(x))
#define chartoint(c) (int)((c) - '0')
#define chartoll(c) (long long)((c) - '0')
#define MOD 1000000007
#define itn int
#define enld endl
#define ednl endl
#define icn cin
#define stirng string
using namespace std;
typedef long long ll;
const double pi = 3.141592653589793;
using Graph = vector<vector<int>>;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b){if(b<a){a=b; return 1;} return 0;}
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int N,M,Q;
int a[55],b[55],c[55],d[55];
int ans;

void dfs(vector<int> A){
    if(SZ(A) == N+1){
        int sum = 0;
        rep(i,0,Q){
            if(A[b[i]] - A[a[i]] == c[i]) sum += d[i];
        }
        chmax(ans, sum);
        return;
    }

    A.push_back(A.back());
    while(A.back() <= M){
        dfs(A);
        A.back()++;
    }
}

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    cin >> N >> M >> Q;
    rep(i,0,Q){
        int x,y,z,w; cin >> x >> y >> z >> w;
        a[i] = x;
        b[i] = y;
        c[i] = z;
        d[i] = w;
    }

    vector<int> v(1,1);
    dfs(v);
    cout << ans << endl;
    return 0;
}