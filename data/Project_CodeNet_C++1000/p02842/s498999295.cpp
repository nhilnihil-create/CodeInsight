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
int a=0,b=0,c=0,d=0,n=0;

//int sa(int n,int p){if(n>=p)return n-p;else return p-n;}

signed main(){
    
        cin>>n;
        a=n/27;
        b=n%27;
        if(b==13||b==26)cout<<":("<<endl;
        else if(b==0)c=a*25;
        else if(b>13)c=n-(2*a+1);
        else c=n-(2*a);
        if(b!=13&&b!=26) cout<<c<<endl;

}