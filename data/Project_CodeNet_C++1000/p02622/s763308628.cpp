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
//define
#define int long long
#define rep(i,n) for(int i=0; i<n; i++)
//グローバル変数宣言
int a=0,b=0,c=0;

signed main(){
    string s,t;
    cin>>s>>t;
    for(int i=0;i<s.size();i++){
        if(s[i]!=t[i])a++;
    }
    cout<<a<<endl;
}
