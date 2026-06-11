
/********************************************************
 **░██████╗██╗░░░░░░█████╗░██╗░░░██╗██╗░█████╗░░██████╗░**
 **██╔════╝██║░░░░░██╔══██╗██║░░░██║██║██╔══██╗██╔════╝░**
 **╚█████╗░██║░░░░░███████║╚██╗░██╔╝██║██║░░╚═╝██║░░██╗░**
 **░╚═══██╗██║░░░░░██╔══██║░╚████╔╝░██║██║░░██╗██║░░╚██╗**
 **██████╔╝███████╗██║░░██║░░╚██╔╝░░██║╚█████╔╝╚██████╔╝**
 **╚═════╝░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░╚════╝░░╚═════╝░**
 *********************************************************/

#include <bits/stdc++.h>
using namespace std;


#define ll                          long long
#define ld                          long double

#define forn(i,n)                   for(int i=0;i<n;++i)
#define all(v)                      v.begin(), v.end()
#define rall(v)                     v.rbegin(),v.rend()
#define isSubstring(s1,s2)          s1.find(s2) != std::string::npos

#define pb                          push_back
#define pf                          push_front
#define mp                          make_pair
#define fr                          first
#define sc                          second

#define vpi                         vector<pair<int,int>>
#define vi                          vector<int>
#define sz(a)                       (int)a.size()

#define   endl                       "\n"
#define     nl                       cout<<"\n";
#define fastio                       ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define  MN                           INT_MIN
#define  MX                           INT_MAX

bool isPrime(ll n){if(n<2)return false;for(ll x = 2;x*x <=n;x++){if(n%x == 0)return false;}return true;}
bool isPerfectSquare(long double x){long double sr=sqrt(x);return((sr-floor(sr))==0);}
int gcd(int a, int b){if(a==0)return b;if(b==0) return a;if(a==b)return a;if(a>b)return gcd(a-b,b);return gcd(a,b-a);}

bool check(string s, int len,int n){
    unordered_map<string,int> m;
    for(int i = 0;i < n - len + 1;i++)
    {
        if( m[s.substr(i, len)] == 0)
        {
            m[s.substr(i, len)] = i+len-1;
        }
        if(m[s.substr(i,len)] > 0 &&  i > m[s.substr(i,len)])return true;
    }
    return false;
}
int32_t main()
{
    fastio
    int n;
    string s;
    cin >> n >> s;
    int l = 0, r = n / 2 ;
    int ans = 0;
    while(l<=r)
    {
        int mid = l + (r-l) / 2;
        if(check(s,mid, n)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << ans << endl;
}
