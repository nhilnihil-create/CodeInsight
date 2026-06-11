#include<bits/stdc++.h>
#include<array>
#define nguyendz the_best


#define ll long long
#define ld long double
#define pb push_back
#define all(n) n.begin(),n.end()
#define eb emplace_back
#define endl "\n"
#define pll pair<ll,ll>
#define YES cout <<"YES"<<endl;
#define NO cout <<"NO"<<endl;
#define ff first
#define ss second
#define setpre(x) fixed<<setprecision(x)
//do not use "\n" in interactive problem
// ((x|y)-y) (x&(~y))
// __gcd(fibo(x),fibo(y)=fibo(__gcd(x,y))
//so luong tap hop gom d phan tu khac nhau dc tao tu k so phan biet la k mu d
// a+b=(a^b)+2*(a&b)
using namespace std;
const ll maxn=5e5+100;

const ll maxx=1e13;
const ll mod1=1000000007;
const ll mod2=998244353;
priority_queue<pll,vector<pll>,greater<pll>> q;

ll  a[34]= {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("test.txt","r",stdin);
   //   freopen("PHONGHAU.INP", "r", stdin);
    //   freopen("PHONGHAU.OUT", "w", stdout);
 ll t;
 cin>> t;
 t-- ;
 cout <<a[t];

}
