#include <bits/stdc++.h>
using namespace std;

/*
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
*/



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

#define TEST_CASE       int ___T; cin>>___T; for(int cs=1;cs<=___T;cs++)
#define PRINT_CASE      printf("Case %d: ",cs)

#define vpf(v)          for(int i=0;i<v.size();i++){cout<<v[i];if(i!=v.size()-1)cout<<" ";else cout<<"\n";}
#define vsc(v)          for(int i=0;i<v.size();i++)cin>>v[i];

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


int main(){
    
    int a, b;
    cin >> a >> b;

    int ans = -1;

    for(int i = 1; i <= 1250000; i++) {
        int x = (int) i * 0.08;
        int y = (int) i * 0.1;

        if(x == a && y == b) {
            ans = i;
            break;
        } 
    }

    cout << ans << "\n";

    return 0;
}
