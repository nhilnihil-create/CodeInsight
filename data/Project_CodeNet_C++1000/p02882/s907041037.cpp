//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
    long double pi=3.1415926535897932;
    long double a,b,x,y,ans; cin>>a>>b>>x;
    cout<<fixed<<setprecision(10);
    y=2*x/(a*b);
    if(y<=a){
        ans=atan(a*b*b/(2*x))/pi*180;
    }
    else{
        ans=90-atan(a*a*a/(2*(a*a*b-x)))/pi*180;
    }
    cout<<ans<<endl;

}

















































