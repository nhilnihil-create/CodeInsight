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


int k,n;
cin>>k>>n;
int a[n];
for(int i=0;i<n;i++){

  cin>>a[i];

}

int dist = a[n-1]-a[0];

for(int i =1 ;i<n-1;i++){

int x = abs(a[i+1]-k) + a[i];
int y = k - a[i] + a[i-1];
dist = min(dist,min(x,y));
}

cout<<dist<<"\n";
  
  return 0;
}
