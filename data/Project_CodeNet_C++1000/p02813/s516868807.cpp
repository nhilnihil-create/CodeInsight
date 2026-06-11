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
//vector<vector<char> > hyou(N, vector<char>(N));
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
/*順列生成
do {
  // 順列に対する処理
} while (next_permutation(配列変数.begin(), 配列変数.end()));*/
//グローバル変数宣言
 ll p=0,q=0,r=0;

int main(){
   ll n;
   cin>>n;
   vl P(n),Q(n),a(n);
   rep(i,n)cin>>P[i];
   rep(i,n)cin>>Q[i];
   rep(i,n)a[i]=i+1;

      do {
   r++;
   if (a==P)
   {
      p=r;
   }
   if (a==Q)
   {
      q=r;
   }
   
   
} while (next_permutation(a.begin(), a.end()));

   
   
   if(p>q){print(p-q)}else print(q-p);
}