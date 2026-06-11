//include
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath> 
#include <iomanip>
#include <math.h>
#include <utility>
#include <functional>
//using
using namespace std;
using vl = vector <long long>;
using vs = vector <string>;
using vc = vector <char>;
using ll= long long;
using vvl = vector<vector<ll> >;
using vd = vector <double>;
//define
//#define int long long
#define rep(i,n) for(int i=0; i<n; i++)
#define print(n) cout<<n<<endl;
#define sortp(d) sort(d.begin(),d.end()) //1234
#define sortm(d) sort(d.rbegin(),d.rend()) //4321
//素数判定　O(√A) 
bool is_prime(int x){
 if(x<=1) return false;
 for(int i=2;i*i<=x;i++)
 if(x%i==0) return false;
 return true;
 }
//グローバル変数宣言
 ll p=0,q=0,r=0;


int main(){
   ll A,B,M;
   cin>>A>>B>>M;
   vl a(A),b(B),x(M),y(M),c(M);
   rep(i,A)cin>>a[i];
   rep(i,B)cin>>b[i];
   rep(i,M){cin>>x[i]>>y[i]>>c[i];x[i]-=1;y[i]-=1;}
   rep(i,M){p=a[x[i]]+b[y[i]]-c[i];if(i==0)q=p;q=min(p,q);}
   sortp(a);sortp(b);
   print(min(a[0]+b[0],q))
}