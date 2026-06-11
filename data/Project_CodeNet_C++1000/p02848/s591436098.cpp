#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define set_zero(a) memset(a,0,sizeof(a));
#define ll long long
#define PI 2 * acos(0.0)
#define MAX 1000000000
#define INF 1000000 
#define M 1000000007
using namespace std;
int main(){
   ll n;
   cin>>n;
   string s;
   cin>>s;
   if(n == 0){
      cout<<s<<endl;
      return 0;
   }
   map<ll,ll> mp;
   char a = 'A';
   for(ll i = 0;i<26;i++){
        mp[a] = i;
        a++;
   }
   string d;
   char b = 'A';
   for(ll i = 0;i<s.length();i++){
      ll y = (mp[s[i]] + n)%26;
      char f = b+y;
      d.push_back(f);
   }
   cout<<d<<endl;
   return 0;
}