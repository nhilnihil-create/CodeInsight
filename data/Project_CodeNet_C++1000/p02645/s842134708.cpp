#include <bits/stdc++.h>
using namespace std;


void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

#define ll long long
#define ld long double
#define ull unsigned long long
#define ull unsigned long long
#define mod 1000000007
#define pi (3.1415926)

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#define scd(a)  scanf("%lld",&a)
#define scdd(a,b)	scanf("%lld%lld",&a,&b)
#define scddd(a,b,c)	scanf("%lld%lld%lld",&a,&b,&c)
#define ptab(a)	printf("%lld ",a)
#define pdn(a)	printf("%lld\n",a)
#define pddn(a,b)	printf("%lld %lld\n",a,b)
#define pdddn(a,b,c)	printf("%lld %lld %lld\n",a,b,c)

#define Filein(N) freopen("N", "r", stdin);
#define Fileout(N) freopen("N", "w", stdout);

#define forr(n) for(ll i=0;i<n;i++)
#define rev(n) for(ll i=n-1;i>=0;i--)
#define forp(x, y) for(ll i=x;i<y;i++)
#define loop( j, k, in) for (ll i=j ; i<k ; i+=in)

#define en "\n"
#define sp " "
#define eps 1.0E-14
#define l length()
#define preci(x) cout << fixed<<setprecision(x)
#define inf LONG_LONG_MAX
#define ninf LONG_LONG_MIN

ull fastpow(ull a,ull b)
{
  ull wynik=1;
  while (b)
  {
    if (b&1)wynik=(wynik*a)%mod;
    a=(a*a)%mod;
    b>>=1;
  }
  return wynik;
}

bool odd(int n)
    {
        int x = sqrt(n);
    for (int i=2 ; i<=x ; ++i)

    {
        if(n%i == 0)return false;
    }

    return true;
    }
ll fact(int n ){

long long fact =1;

for (int i =2 ;i<=n;++i)

{
    fact*=i;
}
return fact;
}

bool prim(long long a){

long long s = sqrt(a);

for (int i=2 ; i<= s ;++i){

    if (a % i == 0)return false;
}
return true;
}

ll sum (int n ){return ((n*(n+1)) / 2) ;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

bool myfunction (string i,string j) /* this function to check who is grater in
sorting strings as numbers ////////
int n;
    cin>>n;
    vector <string> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];


    sort(arr.begin(),arr.end(),myfunction);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<endl;
*/
{
    int n=i.length();
    int m=j.length();
    if(n==m)
        return (i<j);

    return n<m;
}
long long solve (int a, int b)
{
    return min(a,min(b , (a+b) / 3));
}

int main()
{
    init();
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s; cin>>s;

    cout << s[0] << s[1] << s[2];
}

