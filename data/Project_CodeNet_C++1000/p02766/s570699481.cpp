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


ll n;
int k;
cin>>n>>k;

vector<int> vect;


while (n !=0){
  vect.push_back(n%k);
  n = n/k;
}

cout<<vect.size()<<"\n";
  
  return 0;
}
