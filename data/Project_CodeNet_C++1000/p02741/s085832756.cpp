/*
     Author: Wasi Ur Rahman
     RMSTU,Rangamati,Chittagong,Bangladesh
*/
#include <bits/stdc++.h>
using namespace std;
#define  gcd(a,b) __gcd(a,b)
#define  lcm(a,b) (a*b)/gcd(a,b)
#define  PI acos(-1.0)
#define  sqr(x) ((x)*(x))
#define  min3(a,b,c) min(a,min(b,c))
#define  min4(a,b,c,d) min(d,min(a,min(b,c)))
#define  max4(a,b,c,d) max(d,max(a,max(b,c)))
typedef   pair<int, int> ii;
typedef   std::vector<ii> vii;
#define   vi   std::vector<int>
#define   vll  std::vector<ll>
#define   all(n) n.begin(),n.end()
#define  mpsi std::map<string, int>
#define  pb             push_back
#define  ll             long long int
#define  ln             printf("\n");
#define  fast           ios::sync_with_stdio(false);cin.tie(0)
#define  max3(a,b,c)    max(a,max(b,c))
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)     __builtin_ctzll(x)
#define dec(x,y)        fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
#define  mod           1e9 + 7;
bool prm[1000001];
void sieve()
{
    prm[0] = prm[1] = 1;
    for(ll i = 4 ; i <= 1000000 ; i += 2)
        prm[i] = 1 ;
    for(ll i = 3 ; i * i <= 1000000 ; i += 2)
    {
        if(!prm[i])
        {
            for(ll j = i * i ; j <= 1000000 ; j+= i + i)
                prm[j] = 1 ;
        }
    }
}
const string str[32]={"1", "1", "1", "2", "1", "2", "1", "5", "2", "2", "1", "5", "1", "2", "1", "14", "1", "5", "1", "5", "2", "2", "1", "15", "2", "2",
     "5", "4", "1", "4", "1", "51"};
int main()
{
    fast;
    ll n;
    cin >> n;
    cout << str[n-1] << endl;
}
