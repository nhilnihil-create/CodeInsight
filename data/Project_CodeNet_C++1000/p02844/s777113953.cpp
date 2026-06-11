#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define pb push_back
#define mp  make_pair
#define loop(a,n) for(long long i=a;i<n;i++)
#define vil vector<long long int>
#define vi vector<int>
#define sz(v) v.size()
#define setbits(x)          __builtin_popcountll(x)
#define ff first
#define ss second
using namespace std;


ll gcd(ll a, ll b) {
  if (a == 0)return b;
  return gcd(b % a, a);
}
bool isperfect(ll n) {
  ll y = sqrt(n);
  if (n % y == 0 && y * y == n)return true;
  return false;
}
bool comp(pair<int,int> a, pair<int,int> b) {
    if(a.first == b.first) return a.second>b.second;
  return a.first < b.first;
}
 ll powi(ll a, ll b) {
  ll ans = 1;
  while (b > 0) {
    if (b & 1)ans = (ans * a);
    b = b >> 1;
    a = (a * a);
  }
  return ans;
}
bool isprime(ll n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0)return false;
  }
  return true;
}
bool prime[10000000];
void seive() {

  prime[1] = true;
  for (int i = 2; i * i < 10000000; i++) {

    if (prime[i])continue;
    for (int j = i * i; j < 10000000; j += i) {
      prime[j] = true;
    }

  }
}
string fun(ll n){
    string ans;
    while(n>0){
        ans+=(n%10)+'0';
        n/=10;
    }
    ll s=ans.size();
    if(s<3){
        int y=3-s;
        while(y--) ans+='0';
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 ll n;cin>>n;
  string s;
  cin>>s;
 ll fn=0;
  for(int i=0;i<1000;i++){
      string ans=fun(i);
      //123 124
      //unordered_map<ll,ll> m[2];
      //cout<<ans<<" ";
     char p1=ans[0],p2=ans[1];
     //cout<<p1<<p2;
     ll cnt1=0,cnt2=0;
     int f=0;
     ll m1[n],m2[n];
     int cnt=0;
     for(int j=0;j<n;j++){
         m1[j]=cnt;
         if(s[j]==ans[0]) cnt++;
     }
     cnt=0;
     for(int j=n-1;j>=0;j--){
         m2[j]=cnt;
         if(s[j]==ans[2]) cnt++;
     }
     for(int j=0;j<n;j++){
         if(s[j]==ans[1]){
             if(m1[j]&&m2[j]){
                 fn++;break;
             }
         }
     }
    
  }
  cout<<fn;
}



  