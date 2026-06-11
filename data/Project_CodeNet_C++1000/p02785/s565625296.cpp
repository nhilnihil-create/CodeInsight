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

ll n,k;
cin>>n>>k;
ll a[n];
for(int i=0;i<n;i++){
  cin>>a[i];
}
sort(a,a+n);
int st = n-1;
for(int i=0;i<k;i++){

   a[st] = 0;
   st--;

}

ll num  = 0;

for(int i=0;i<n;i++){
  num += a[i];
}

cout<<num<<"\n";

  
  return 0;
}
