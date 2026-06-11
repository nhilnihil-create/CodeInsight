#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;

int main(){
    double a,b,x;
    cin>>a >> b>> x;
    if(a*a*b/2<x){
        double nokori = a*a*b-x;
        double h = 2*nokori/(a*a);
        cout <<fixed<<setprecision(7)<< 90 -90*atan(a/h)/(M_PI/2)<<endl;
    }else{
        double h = 2*x/(b*a);
        cout <<fixed<<setprecision(7)<< 90 -90*atan(h/b)/(M_PI/2)<<endl;
    }
  
    
    return 0;
}
