#include<iostream>
#include<bits/stdc++.h>
#define mod 1000000007
#define int long long
#define pb(x) push_back(x)
#define gcd(a,b) __gcd(a,b)
#define all(v) v.begin(),v.end()
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int32_t main()
{
   fast;
   #ifndef ONLINE_JUDGE
   freopen("goodluckin.txt","r",stdin);
   freopen("goodluckout.txt","w",stdout);
   #endif
   string s;
   cin >> s;
   int n = s.size();
   for(int i = 0 ; i < s.size() ;i++ ){
     if(s[i]=='?'){
      s[i] = 'D';
     }
   }
   cout << s;
}




