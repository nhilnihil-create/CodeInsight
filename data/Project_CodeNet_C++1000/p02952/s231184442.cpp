#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include<algorithm> 
#include <iomanip>
#include <math.h>
#include <cctype>
//小文字を大文字 c-0x20;


#define db double
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ld long double
#define maxn 5005
#define mod 998244353
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define vv(z,a,b) vector<vector<int>>z(a,vector<int>(b))
#define vvll(z,a,b) vector<vector<ll>>z(a,vector<ll>(b))
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(c) begin(c),end(c)
#define fix(k) fixed<<setprecision(k)
#define PI 3.141592653589793
using namespace std;



int main(){
  int n;cin>>n;
  int flag=0;
  for(int i=1;i<=n;i++){
      if(i==100000)break;
      flag++;
      if(i==9){
          i=99;
          continue;
      }else if(i==999){
          i=9999;
        continue;
      }
  }
cout<<flag<<endl;
}
