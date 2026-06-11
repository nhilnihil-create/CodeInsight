//pragma
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define YOU using
#define DONT namespace
#define SAY std

YOU DONT SAY;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define REPP(i,a,b,d) for(int i=a;i<=b;i+=d)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,d) for(int i=a;i>=b;i-=d)
#define REV(i,a,b) REVV(i,a,b,1)

#define FOR(i,a) for(int i=0; i<a; i++)
#define FORD(i,a) for(int i=(int)a-1; i>=0; i--)

#define pb push_back
#define F first
#define S second

const int OO = 1e9;
const ll INF = 1e18;

const int irand(int lo,int hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

const ll lrand(ll lo,ll hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

#define getc getchar
template<typename T>
T getnum(){
	int sign = 1;
	T ret = 0;
	char c;

	do{
		c = getc();
	}while(c == ' ' || c == '\n');
	if(c == '-')sign = -1;
	else ret = c-'0';
	while(1){
		c = getc();
		if(c < '0' || c > '9')break;
		ret = 10*ret + c-'0';
	}
	return sign * ret;
}

inline void ini(int& x){
	x = getnum<int>();
}

inline void scani(int& x){
	scanf("%d",&x);
}

//end of macro

const ll MOD = 1e9 + 7;

inline ll addmod(ll a, ll b){
    return (a+b)%MOD;
}

const int N = 2e3 + 5;

int n,m;
int a[N], b[N];

int memo[N][N][2];
// stage 0 -> init, choose to take or skip
// stage 1 -> searching on b
int dp(int p, int q, int stage){
    if(p > n)return 1;
    if(q > m){
        if(stage == 0)return 1;
        return 0;
    }
    int& ret = memo[p][q][stage];
    if(ret != -1)return ret;
    
    ret = 0;
    
    if(stage == 0){
        // skip
        ret = addmod(ret, dp(p+1, q, 0));
        
        // take
        ret = addmod(ret, dp(p, q, 1));
    }else{
        ret = addmod(ret, dp(p, q+1, 1)); // stil searching
        
        // take this
        if(a[p] == b[q]){
            ret = addmod(ret, dp(p+1, q+1, 0));
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);
    
    cin>>n>>m;
    REP(i,1,n)cin>>a[i];
    REP(i,1,m)cin>>b[i];
    
    memset(memo, -1, sizeof memo);
    cout << dp(1, 1, 0) << endl;
    
    return 0;
}