#include <bits/stdc++.h>
using namespace std;

//____________________________________________________________________________________________________________________________________

#define PI  2*acos(0.0)
#define pf  printf
#define sf  scan
#define ff  first
#define ss  second
#define mp  make_pair
#define pb  push_back
typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef vector<long long> vll ;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define sc(n)       scanf("%d",&n);
#define scf(f)      scanf("%f",&f);
#define FOR(i,a,n)  for(int i = a; i < n; i++)
#define TEST(test)  for(int cse = 1; cse <= test; cse++)
#define all(x) (x).begin(), (x).end()
#define fap(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mst(arr, n) memset(arr, n, sizeof arr)
const ll INF = 2000000000000000000LL;
const int inf = 0x3f3f3f3f;
const long double EPS = 1e-9;
const ll MOD = 1e9 + 7;
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
//____________________________________________________________________________________________________________________________________
const int maxn = 1e5 + 8;
ll range, n, qsum[maxn];


ll f(vll &v, ll i, ll mx_brach)
{
   if(i > n) return 0;

   ll branch = mx_brach - v[i];
   
   if(branch < 0) return -1;

   range = qsum[i + 1];
   branch = min(branch, range);

   if( i == n) return v[i];
   ll sum = f(v, i + 1, branch * 2);

   if(sum == -1){
      return sum;
      }

   return branch + v[i] + sum;
}


int main()
{
#ifdef PARTHO
   freopen("C:\\Users\\rnoji\\Desktop\\Partho Code\\IO\\input.txt","r",stdin);
   freopen("C:\\Users\\rnoji\\Desktop\\Partho Code\\IO\\output.txt","w",stdout);
   int start_time = clock();
#endif
//FastIO

cin >> n;

vll v(n + 1);

for(auto &it : v) cin >> it;

qsum[n] = 0;
for(int i = n; i >= 0; i--)
   qsum[i] = v[i] + qsum[i + 1];

range = qsum[0];

ll sum = 0;

if(range == 0)sum = -1;
else sum = f(v, 0, 1);

cout << sum << endl;


#ifdef PARTHO
   int end_time = clock();
   printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
#endif

    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1





