#include<bits/stdc++.h>
using namespace std ;
 
#define int long long

#define IOS ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
 
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vp vector<pii>
#define vs vector<string>
#define all(v) v.begin(),v.end()

#define lb  lower_bound
#define ub  upper_bound
#define bs  binary_search
#define ff  first
#define ss  second
#define sz(x) ((int)(x).size())
#define rep(i,l,r) for(int i=(l);i<(r);++i)
 
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
     
#define pi 3.14159265358979323846//20 decimals
#define MOD 1000000007

 
int32_t main(){

   //  #ifndef ONLINE_JUDGE
   // freopen("input.txt", "r", stdin);
   //  freopen("output.txt", "w", stdout);
   //  #endif
     IOS
    // // 
    string s;
    cin>>s;
   string ans="Good";
   for(int i=0;i<sz(s)-1;i++)
      {
        if(s[i]==s[i+1])
        {
            ans="Bad";break;
        }
    }
    cout<<ans;
return 0;
}