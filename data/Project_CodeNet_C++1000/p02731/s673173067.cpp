#include<bits/stdc++.h>
using namespace std;
#define intt long long int
#define intu unsigned long long int
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
//#define mp make_pair
#define ff first
#define ss second
#define fast_io ios::sync_with_stdio(0);cin.tie(NULL);std::cout.tie(NULL);
# define PI           3.14159265358979323846 
#define all(a) a.begin(),a.end()
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define loop(i,a,b) for (int i = a; i < b; i++)
#define bloop(i,a,b) for (int i = a ; i>=b;i--)
#define tc(t) int t; cin >> t; while (t--)
int mod = 1000000007;
int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}
int lcm(int a, int b) {return a * b / gcd(a, b); }
intt bpow(intt a,intt b) 
{
  intt res = 1;
  while (b > 0) {
    if (b & 1)res = ((res%mod) * (a%mod))%mod;
      a = ((a%mod) * (a%mod))%mod;
      b >>= 1;
  }
  return res;
}
intt fact(intt n) { 
   if ((n==0)||(n==1))
      return 1; 
   else
      return n*fact(n-1);
}
void go()
{
#ifndef ONLINE_JUDGE
  freopen("inn.txt","r",stdin);
  freopen("ouut.txt","w",stdout);
  #endif
}
///////////U L R D
int dx[4]={0,-1,1,0};
int dy[4]={1,0,0,-1};


int main() 
{ 
    fast_io
    go();
   long double n;cin>>n;
   long double ans=n/3*n/3*n/3;
   cout << fixed << setprecision(12) << ans <<"\n";
}

/*!
    You are under no obligation to be the same person you were a minute ago,
    You have the right to grow !
*/


















