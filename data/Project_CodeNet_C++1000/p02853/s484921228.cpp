#include <bits/stdc++.h>
using namespace std;
 
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=(s);i<(n);i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define REPR(i,s,n) for(int i=(s);i>=(n);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define Eunique(v) v.erase(unique(all(v)),v.end())
#define pvec(v) rep(i,v.size()){cout << v[i] << " ";};cout<<endl;
#define pb push_back
#define pf push_front
#define mod 1000000007
#define m_p make_pair
#define DOUBLE fixed << setprecision(15)
#define OK puts("OK")
#define OK1 puts("OK1")
#define OK2 puts("OK2")
#define Endl cout << endl
#define SIZE(s) (int)s.size()
#define Cout(n) cout<<(n)<<endl

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
const double pi = acos(-1.0);
 
ll gcd(ll x, ll y) { return (y == 0) ? x : gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }

bool substring_search(string s,string key){
    int count=0;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]==key[count]) count++;
        if(count==(int)key.size()) return true;
    }
    return false;
}

int main()
{
    ll x,y,ans=0;
    cin >> x >> y;
    if(x<4) ans+=(4-x)*100000;
    if(y<4) ans+=(4-y)*100000;
    if(x==y && x==1) ans+=400000;
    Cout(ans);
    return 0;
}
