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
#define print(n) cout<<n<<endl;
//グローバル変数宣言
long long a=0,b=0,c=0,d=0,n=0;

signed main(){
    cin>>a>>b;
    if(a==1 || b==1)print(1)
    else if(a%2==1&&b%2==1){print((a*b+1)/2)}
    else print(a*b/2);
    
}