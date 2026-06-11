#include <bits/stdc++.h>
using namespace std;


//************** StrAnge.R *********************

#define ll              long long int
#define ull             unsigned long long
#define ld              long double
#define lll             __int128
#define vi              vector<int>
#define vl              vector<ll>
#define vvi             vector<vector<int> >
#define pii             pair<int,int>
#define piii            pair<int,pair<int,int> >
#define pll             pair<ll,ll>
#define vii             vector<pii>

#define sz(v)           ((int)(v).size())
#define all(s)          s.begin(),s.end()
#define allr(s)         s.rbegin(),s.rend()
#define unq(c)          (sort(all(c)), c.resize(distance(c.begin(),unique(all(c)))))
#define get_pos(c,x)    (lower_bound(all(c),x)-c.begin())

#define MS0(v)          memset((v), 0, sizeof((v)))
#define MS1(v)          memset((v), -1, sizeof((v)))
#define LEN(v)          strlen(v)

#define MP              make_pair
#define pb              push_back
#define pob             pop_back
#define ff              first
#define ss              second
#define sc              scanf
#define pf              printf
#define endl            "\n"

#define LL              ({ll __LL; scanf("%lld",&__LL); __LL;})
#define II              ({int __II; scanf("%d",&__II); __II;})
#define CC              ({char __CC; scanf("%c",&__CC); __CC;})
#define DD              ({double __DD; scanf("%lf",&__DD); __DD;})

#define TEST_CASE       int ___T; scanf("%d",&___T); for(int cs=1;cs<=___T;cs++)
#define PRINT_CASE      printf("Case %d: ",cs)

#define vpf(v, len)     for(int ix=0;ix<len;ix++){pf("%d",v[ix]);if(ix!=len-1)pf(" ");else pf("\n");}
#define vsc(v, len)     for(int ix=0;ix<len;ix++)scanf("%d",&v[ix]);

#define REP(i, n)       for (int i = 0; i < (n); i++)
#define REPP(i, a, b)   for (int i = (a); i < (b); i++)
#define FOR(i, a, b)    for (int i = (a); i <= (b); i++)
#define FORS(i, s)      for (int i = 0; s[i]; i++)

#define fastio          ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fileio          freopen("in.txt","r",stdin);freopen("out.txt","w",stdout)

#define intlim          2147483648
#define infinity        (1LL<<50)
#define intmx           INT_MAX
#define PI              3.14159265358979323846264338327950L // acos(-1.0)

#define gcd(a, b)       __gcd(a, b)
#define lcm(a, b)       ((a)*((b)/gcd(a,b)))


int on_bit(int N,int pos){return N = N | (1<<pos);}
int off_bit(int N,int pos){return N = N & ~(1<<pos);}
bool check_bit(ll N,int pos){return (bool)(N & (1<<pos));}


#define start_clock     clock_t tStart = clock()
#define end_clock       printf("\n>>Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC)

template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}


//******************* my code starts here **********************************

int n, m, q;
int qq[55][5];

vector<int> v = {0};

ll solve(int num) {
    if((int) v.size() == n+1) {
        ll ret = 0;

        for(int i = 1; i <= q; i++) {
            int ai = qq[i][1], bi = qq[i][2], ci = qq[i][3], di = qq[i][4];

            if((v[bi] - v[ai]) == ci) ret += di;
        }
        return ret;
    }
    if(num > m) return 0;

    ll ret = 0;

    v.push_back(num);
    ret = max(ret, solve(num));
    v.pop_back();

    ret = max(ret, solve(num+1));
    return ret;
}

int main(){
    
    cin >> n >> m >> q;

    for(int i = 1; i <= q; i++) {
        for( int j = 1; j <= 4; j++) {
    
            cin >> qq[i][j];
        }
    }

    ll ret = solve(1);

    cout << ret << "\n";

    return 0;
}
