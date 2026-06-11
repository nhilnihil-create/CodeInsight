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
intt gcd(intt a, intt b) {return b ? gcd(b, a % b) : a;}
intt lcm(intt a, intt b) {return a * b / gcd(a, b); }
intt bpow(intt a,intt b) 
{
  intt res = 1;
  while (b > 0) {
    if (b & 1)res = ((res) * (a));
      a = a * a;
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
 
template <typename T1, typename T2>
struct less_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second > b.second;
    }
};
 
int main() 
{ 
    fast_io
    go();
    int h1,s1,h2,s2;cin>>h1>>s1>>h2>>s2;
    bool f=0;
    while(1)
    {
      if(h1<=0)
      {
        cout << "No" <<"\n";
        break;
      }
      else if(h2<=0)
      {
        cout << "Yes" <<"\n";
        break;
      }
      if(!f)
      {
        f=1;
        h2-=s1;
      }
      else if(f)
      {
        f=0;
        h1-=s2;
      }
    }
    
}
 
 
 
/*
2
6


*/
 
 
 
 
 
 