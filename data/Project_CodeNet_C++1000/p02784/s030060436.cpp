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

 ll h;
 int n;
 cin>>h>>n;
 int a[n];
 ll sum = 0;
 for(int i=0;i<n;i++){
   cin>>a[i];
   sum +=a[i];
 }

 if( sum >= h){
   cout<<"Yes\n";
 }
 else{
   cout<<"No\n";
 }


  
  return 0;
}
