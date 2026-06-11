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
//vector<vector<int> > hyou(N, vector<int>(N));
//define
#define int long long
#define rep(i,n) for(int i=0; i<n; i++)
#define print(n) cout<<n<<endl;
//グローバル変数宣言
int a=0,b=0,c=0,e=0,n=0,k=0;


signed main(){
   cin>>n;
   vector<int>d(n);
   rep(i,n)cin>>d[i];
   a=n/2;
   sort(d.begin(),d.end());
   b=d[a-1];
   c=d[a];
   print(c-b);
}
