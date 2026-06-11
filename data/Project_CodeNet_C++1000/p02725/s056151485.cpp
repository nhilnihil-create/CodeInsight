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
/*using vi = vector <int>;
using vs = vector <string>;
using vc = vector <char>;*/
//vector<vector<char> > hyou(N, vector<char>(N));
//define
#define int long long
#define rep(i,n) for(int i=0; i<n; i++)
#define print(n) cout<<n<<endl;
//グローバル変数宣言
int b=0,c=0,d=0,n,k;

signed main(){
   cin>>k>>n;
   vector<int>a(n);
   rep(i,n)cin>>a[i];
   rep(i,n){
       if(i==0)b=a[i]+k-a[n-1];
       else b=max(a[i]-a[i-1],b);
       }
       print(k-b);
}
