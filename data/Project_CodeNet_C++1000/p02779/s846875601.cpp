#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); i++)

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);


ll gcd(ll a, ll b){  if(b==0){  return a; }   return gcd(b , a%b); }


int main() {

  int n;
  cin>>n;
  unordered_map<long long , long long > umap;
  
  for(int i=0;i<n;i++){
    long long x;
    cin>>x;
    umap[x]++;
  }
  
  if(umap.size() == n){
    cout<<"YES\n";
  }
  else{
    cout<<"NO\n";
  }  


  
  return 0;
}
