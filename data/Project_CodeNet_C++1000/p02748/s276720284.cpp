                             ///......বিসমিল্লাহির রাহমানির রাহিম......///
                ///......পরম করুণাময় অসীম দয়ালু আল্লাহতায়ালার নামে শুরু করছি.....///
/*

─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
─████████████████───██████──██████────────████████████████───██████████████─██████████████─██████████████─██████─────────
─██░░░░░░░░░░░░██───██░░██──██░░██────────██░░░░░░░░░░░░██───██░░░░░░░░░░██─██░░░░░░░░░░██─██░░░░░░░░░░██─██░░██─────────
─██░░████████░░██───██░░██──██░░██────────██░░████████░░██───██░░██████░░██─██░░██████████─██░░██████████─██░░██─────────
─██░░██────██░░██───██░░██──██░░██────────██░░██────██░░██───██░░██──██░░██─██░░██─────────██░░██─────────██░░██─────────
─██░░████████░░██───██░░██████░░██────────██░░████████░░██───██░░██████░░██─██░░██████████─██░░██████████─██░░██─────────
─██░░░░░░░░░░░░██───██░░░░░░░░░░██────────██░░░░░░░░░░░░██───██░░░░░░░░░░██─██░░░░░░░░░░██─██░░░░░░░░░░██─██░░██─────────
─██░░██████░░████───██░░██████░░██────────██░░██████░░████───██░░██████░░██─██████████░░██─██░░██████████─██░░██─────────
─██░░██──██░░██─────██░░██──██░░██────────██░░██──██░░██─────██░░██──██░░██─────────██░░██─██░░██─────────██░░██─────────
─██░░██──██░░██████─██░░██──██░░██─██████─██░░██──██░░██████─██░░██──██░░██─██████████░░██─██░░██████████─██░░██████████─
─██░░██──██░░░░░░██─██░░██──██░░██─██░░██─██░░██──██░░░░░░██─██░░██──██░░██─██░░░░░░░░░░██─██░░░░░░░░░░██─██░░░░░░░░░░██─
─██████──██████████─██████──██████─██████─██████──██████████─██████──██████─██████████████─██████████████─██████████████─
─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────

*/
#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#include <set>

///...define...///
#define S scanf
#define P printf
#define D   double
#define ll  long long
#define ull unsigned long long

///...Input...///
#define S1(a)      scanf("%d",&a)
#define S2(a,b)    scanf("%d%d",&a,&b)
#define S3(a,b,c)  scanf("%d%d%d",&a,&b,&c)
#define SL1(a)     scanf("%lld",&a)
#define SL2(a,b)   scanf("%lld%lld",&a,&b)
#define SL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)

///...Declared Input...///
#define DI(X)          int X;      scanf("%d", &X)
#define DII(X, Y)      int X,Y;    scanf("%d%d", &X, &Y)
#define DIII(X, Y, Z)  int X,Y,Z;  scanf("%d%d%d", &X, &Y, &Z)
#define DLI(X)         ll X;       scanf("%lld", &X)
#define DLII(X, Y)     ll X,Y;     scanf("%lld%lld", &X, &Y)
#define DLIII(X, Y, Z) ll X,Y,Z;   scanf("%lld%lld%lld", &X, &Y, &Z)

///...Loop...///
#define fai(i,a)        for(int i=0; i<a; i++)
#define faj(j,a)        for(int j=0; j<a; j++)
#define fab(a, b)       for(int i=a; i<=b; i++)
#define rfai(i, a)        for(int i=a-1; i>=0; i--)
#define fabi(a,b,inc)   for(int i=a; i<=b; i+=inc)
#define fabd(a,b,dec)   for(int i=a; i>=b; i-=dec)

///...Minimum/Maximum...///
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define mxe(a,n)   (*max_element(a,a+n))
#define mne(a,n)   (*min_element(a,a+n))

///...PrintCase...///
#define PC(a)      printf("Case %d: ",a)
#define PCN(a)     printf("Case %d:\n",a)
#define PCH(a)     printf("Case #%d: ",a)

///...Pair...///
#define ff  first
#define ss  second
#define MP  make_pair
#define vec  vector< int >
#define vv vector< vi >
#define vll vector< ll >
#define pii pair< int , int >
#define pll pair< ll , ll >
#define vpi vector< pii >


///...Other Operations...///
#define pi         2.0*acos(0.0)
#define eps        1e-11
#define sqr(n)     n*n
#define all(a)     a.begin(),a.end()
#define nl         "\n"
#define check      P("here\n")
#define gch        getchar()
#define pb         push_back
#define pp         pop_back
#define sz()       size()
#define SUM(a,n)   accumulate(a,a+n,0)
#define READ(f)    freopen(f, "r", stdin)
#define WRITE(f)   freopen(f, "w", stdout)

///...define mathematics...///
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define MAX 1000000

using namespace std;

///...Mathematics...///
template <typename T> T BigMod(T b,T p,T m){if(p==0)return 1;if(p%2==0){T s=BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T POW(T B,T P){    if(P==0)        return 1;    if(P&1)    return B*POW(B,P-1);    else      return sqr(POW(B,P/2));}
template <typename T> T gcd(T a,T b){    if(a<0)        return gcd(-a,b);    if(b<0)        return gcd(a,-b);    return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a,T b){    if(a<0)        return lcm(-a,b);    if(b<0)        return lcm(a,-b);    return a*(b/gcd(a,b));}



///...String Operation...///

int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
ll toLlint(string s) { ll sm; stringstream ss(s); ss>>sm; return sm; }
bool isVowel(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false; }
template <class T> string NTS ( T Number ){stringstream ss;ss << Number;return ss.str();}
bool isprime(int w){if(w == 0) return false;if(w == 1) return false;int sqrtw = int(sqrt((double)w));for(int q = 2; q <= sqrtw; q++){if(w % q == 0) return false;}return true;}

#define   IOS   {ios_base::sync_with_stdio(0); cin.tie(0);}

///.............End Of Template..............////
int b2d(long long n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}
int main()
{  IOS;
	
   int A, B, M;
   cin >> A >> B >> M;
	vec a(A);
	vec b(B);
	for (int i = 0; i < A; i++)cin >> a[i];
	 for (int i = 0; i < B; i++)cin >> b[i];
	int minA = *min_element(all(a));
	int minB = *min_element(all(b));
	int ans = minA+minB;
	for (int i = 0; i < M; i++) {
	int x, y, c;
	cin >> x >> y >> c; x--; y--;
	 ans = min(ans, a[x] + b[y] - c);
	}
	 cout << ans << endl;

}