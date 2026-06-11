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
int main()
{
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int m1,d1,m2,d2;
  cin>>m1>>d1>>m2>>d2;
  int f=0;
  if(m1<=7){
   if(m1%2==0&&m1!=2){
       if(d1==30) f=1;
   }
   else if(m1%2!=0)
   {
       if(d1==31) f=1;
   }else{
       if(m1==2&&d1==28) f=1;
   }
  }else{
       if(m1%2!=0){
       if(d1==30) f=1;
   }
   else if(m1%2==0&&m1!=2)
   {
       if(d1==31) f=1;
   }
  }
   cout<<f;
      
}



  