//                          **********  YATIN KWATRA  ********** 

//AC bakshi Rabha

#include <bits/stdc++.h>
#define ll                      long long 
#define ull                     unsigned long long 
#define FIO                     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl                    "\n"
#define fo(i,a,b)               for(int i = a; i<=b ; i++)
#define rfo(i,a,b)              for(int i = a; i>=b ; i--)
#define vii                      vector<int>
#define vll                     vector<ll>
#define pq                      priority_queue
#define uom                      unordered_map                
#define all(v)                  v.begin(),v.end()
#define mp                      make_pair
#define pb                      push_back
#define pob                     pop_back
#define ff                      first
#define ss                      second
#define pii                     pair<int,int> 
#define pll                     pair<long,long>
#define mll                     map<ll,ll>
#define mii                     map<int,int>
#define vvii                    vector<vii>
#define vvll                    vector<vll>
#define mod                     1000000007
#define pi                      3.1415926535897932384626433832795
// #define node                    Node

using namespace std;

void INPUT() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

}
#define m 998244353

ll power(ll n, ll p)
{
    if(p == 0) return 1LL;

    ll res = 1LL;

    while(p)
    {
        if(p&1){

            res *= n;
            res%=m;
        }

        p >>= 1;
        n *= n;
        n%=m;
    }

    return res;
}

ll cnt;

ll f(vvll &dp, vll &v, ll n, ll i, ll s)
{
    if(s == 0) return power(2,n-i);

    if(i == n) return 0LL;

    if(dp[i][s] != -1 ) return dp[i][s];


    // Case-> Take it or leave it

    ll op1 = 0, op2 = 0;

    if(s>=v[i]) op1 = f(dp,v,n,i+1,s-v[i]);
                op2 = 2*f(dp,v,n,i+1,s);

    op1 %= m;
    op2 %= m;

    dp[i][s] = op1+op2;

    dp[i][s] %= m;

    return dp[i][s];
}

void solve()
{ 
        ll n,s,x;
        cin >> n >> s;

        vll v(n);
        cnt = 0; 

        fo(i,0,n-1)
        {
            cin >> v[i];
        } 

        sort(all(v));

    //    fo(i,0,n-1) cout << v[i] << " ";
      //  cout << endl;

        vvll dp(n+1,vll(s+1,-1));

    //    cout << power(2,6) << " " << power(3,5) << endl;
        cout << f(dp,v,n,0LL,s) << endl;

    
       
}
int main() {
    
    FIO
    INPUT();
    
    int t;
    t = 1;
 //   cin >> t;
    
    while(t--)
    {
       solve();
    }
    return 0;
}
