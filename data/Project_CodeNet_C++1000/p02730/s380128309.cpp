#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
#define pii pair<int,int>
#define pll pair<long long,long long>
#define usi unordered_set<int>
#define usl unordered_set<long long>
#define umii unordered_map<int,int>
#define umsi unordered_map<string,int>
#define umll unordered_map<long long,long long>
#define fi first
#define sec second
#define pub push_back
#define pob pop_back
#define B begin
#define E end
#define mp make_pair
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pii>
#define vll vector<pll>
#define deb(x) cout<<#x<<": "<<x<<"\n"
#define endl '\n'
#define PIE 3.141592653
#define MOD 1000000007
#define f(i,a,b,c) for(ll i=a;i<=b;i+=c)
#define frev(i,n,b,c)  for(ll i=n;i>=b;i-=c)
const ll inf = 1000000000000000000;
using namespace std;
 
//            < = = = = =    GCD     = = = = = >
 
ll gcd(ll a,ll b)
{
    if(a<b) gcd(b,a);
    if(b==0)    return a;
    return gcd(b,a%b);
}
 
//            < = = = = =    LCM     = = = = = >
 
ll lcm(ll a,ll b) 
{ 
    ll x=(a/gcd(a,b))*b; 
    return x;
}
 
//            < = = = = =    power  x^n     = = = = = >
 
ll power(ll x , ll n , ll m=inf){
    if(x==0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    ll ans;
    if(n%2==0){
        ll smallAns = power(x,n/2,m);
        ans = (smallAns*smallAns)%m;        
    } else {
        ll smallAns = power(x,n-1,m);
        ans = x;
        ans = (ans*smallAns)%m;
    }
    // for negative values also
    return (ans+m)%m;
    
}
 
//            < = = = = =    CHECK FOR PRIME     = = = = = >
 
bool isprime(int n){
   if(n==2){
        return true;
    }
    else if(n%2==0){
        return false;
    }
    else{
        for(int i=3;i*i<=n;i+=2){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
}
 
//            < = = = = =    SOLVE    = = = = = >
 
 //  void generate() {
//     memset(div, 0, sizeof div);
//     for (int i = 1; i <= N; i++) {
//         for (int j = i; j <= N; j += i) {
//             divisors[j] += 1;
//         }
//     }
// }

// bool cmp(pll x, pll y){
//     ll dx = min(2*(x.first),x.second)-min(x.first,x.second);
//     ll dy = min(2*(y.first),y.second)-min(y.first,y.second);
//     return dx>dy;
// }
 
// void rec(int ){
//     if(){

//         return 0;
//     }

//     return ;
// }
 
int solve() {fastio
       string s;
       cin>>s;
       string k = s;

       int n = s.length();
       string sl = s.substr(0,(n-1)/2);
       string sr = s.substr(((n+3)/2)-1);
       string rsr=sr,rsl=sl;
       reverse(rsl.begin(),rsl.end());
       reverse(rsr.begin(),rsr.end());
       int vbn = 0;
       if(rsr==sr)vbn++;
       if(rsl==sl)vbn++;
       reverse(k.begin(),k.end());

       if(k==s)vbn++;
       if(vbn==3)cout<<"Yes";
       else cout<<"No";
       
    return 0;
}
    
//            < = = = = =    MAIN     = = = = = >
 
int main() {fastio

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int t=1;
    //  cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
