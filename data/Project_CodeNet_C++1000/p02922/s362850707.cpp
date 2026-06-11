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
    a-=1;//+a
    b-=1;//b+
    if(b%a==0)cout<<b/a<<endl;
    else cout<<b/a+1<<endl;
}