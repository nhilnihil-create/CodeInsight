#include <bits/stdc++.h>
using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pl= pair<ll,ll>;
using ld=long double;
using V=vector<int>;
using Vl=vector<ll>;
using VV=vector<vector<int>>;
using VVl=vector<vector<ll>>;

int main(){
    ld a,b,x;cin >>a>>b>>x;
    ld ans;
    ld pi=3.14159265358979323;
    if(2*x>a*a*b){
        ld k=(2*a*a*b-2*x)/(a*a*a);
        ans=atan(k);
    }
    else {
        ans=atan(a*b*b/(2*x));
    }
    cout <<setprecision(15)<<ans*180/pi<<endl;
}
