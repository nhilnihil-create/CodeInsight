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
using vi = vector <int>;
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
//グローバル変数宣言
 ll a=0,b=0,c=0,e=0,n=0,k=0;


int main(){
   cin>>n;
   vd v(n);
   rep(i,n)cin>>v[i];
   sortm(v);
   rep(i,n-1){
      v[n-i-2]=(v[n-i-1]+v[n-i-2])/2;
   }
   print(v[0]);
}
