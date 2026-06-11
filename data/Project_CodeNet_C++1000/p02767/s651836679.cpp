//include
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath> 
#include <iomanip>
#include <math.h>
#include <utility>
//using
using namespace std;
/*using vi = vector<int>;
using vs = vector<string>;
using vc = vector<char>;*/
//define
#define int long long
#define rep(i,n) for(int i=0; i<n; i++)
//グローバル変数宣言
int a=0,b=0,c=0,d=0,e=0;

//int sa(int n,int p){if(n>=p)return n-p;else return p-n;}

signed main(){
    cin>>a;
    vector<int>x(a);
    rep(i,a){cin>>x[i]; b+=x[i];}
    c=b/a;
    rep(i,a)d+=(c-x[i])*(c-x[i]);
    rep(i,a)e+=(1+c-x[i])*(1+c-x[i]);
    cout<<min(d,e)<<endl;
}