#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define pb push_back
#define mpr make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ll long long
#define ld long double
#define all(arr) arr.begin(), arr.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define fo(i, l, r) for (int i = l; i <= r; i++)
#define INF 1000000001
#define inf1 1000000000000000001
#define mod 1000000007
#define pie 3.14159265358979323846264338327950L
#define N 100005
#define mid(l, r) l + (r - l) / 2
#define vec vector<int>
#define vecl vector<ll>
#define umap unordered_map<ll,ll>
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define endl "\n"
using namespace std;
 
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};  
int ddx[8]={1,1,0,-1,-1,-1,0,1},ddy[8]={0,1,1,1,0,-1,-1,-1};
ll gcd(ll a,ll b){ if(!a)return b;return gcd(b%a,a);}
ll lcm(ll a, ll b) { return (a*b)/ gcd(a,b);}





void test_case() {

    
    

   int n , p;
   cin>>n>>p;

   string s;
   cin>>s;

   if( 10 % p == 0) {

       ll ans = 0;
       for(int i=n; i>=1; i--) {
           ll val = s[i-1] - '0';

           if(val % p == 0) {
               ans+= i;
           }
       }

       cout<<ans<<endl;
       return;
   }

   ll ans = 0;

   ll mul = 1;
   vecl L(p+1, 0);
   L[0] = 1;

   ll r = 0;

   for(int i=n-1; i>=0; i--) {
       r = ((s[i] - '0') * mul + r) % p;
       ans+= L[r];
       L[r]++;
       mul = (mul * 10) % p;
   }

   cout<<ans<<endl;




}
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(20);
 
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
 
 
    int t = 1;
    // cin >> t;
    while (t--)
    {
        test_case();
    }
}
