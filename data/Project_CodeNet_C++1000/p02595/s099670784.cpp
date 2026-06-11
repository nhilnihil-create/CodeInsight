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
int a=0,b=0,c=0;

signed main(){
    cin>>a>>b;
    vector<int>x(a),y(a);
    rep(i,a)cin>>x[i]>>y[i];
    rep(i,a){if(b*b>=x[i]*x[i]+y[i]*y[i])c++;}
    cout<<c<<endl;
}