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
int a=0,b=0,c=0,d=0,e=0,n,k;

int sa(int x,int y)
{
if (x>k)
{
   return k;
}else return x;
}

signed main(){
   cin>>n>>k;
   a=n/k;
   if (n-a*k>(a+1)*k-n)
{
   b= (a+1)*k-n;
}else b= n-a*k;

   print(b);
}
