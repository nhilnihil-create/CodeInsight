#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
#define F first
#define S second
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#ifdef dremix
    #define p(x) cerr<<#x<<" = "<<x<<endl;
    #define p2(x,y) cerr<<#x<<" , "<<#y<<" = "<<x<<" , "<<y<<endl;
    #define pp(x) cerr<<#x<<" = ("<<x.F<<" , "<<x.S<<")"<<endl;
    #define pv(x) cerr<<#x<<" = {";for(auto u : x)cerr<<u<<", ";cerr<<"}"<<endl;
    #define ppv(x) cerr<<#x<<" = {";for(auto u : x)cerr<<u.F<<"-"<<u.S<<", ";cerr<<"}"<<endl;
#else
    #define p(x)
    #define p2(x,y)
    #define pp(x)
    #define pv(x)
    #define ppv(x)
#endif
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int maxp = 22;
const ld EPS = 1e-18;
const ll INF = 1e18;
const int MOD = 1e9+7;
const int N = 2e5+1;


int main(){
fastio

int n;
cin>>n;

string s = "ACL";

int i;
string ans = "";

for(i=0;i<n;i++)ans += s;

cout<<ans<<endl;



}
