#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1001001001;
const long long MOD = 1000000007;
const double EPS = 1e-10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    double a,b,x;
    cin>>a>>b>>x;
    x/=a;
    double PI=acos(-1);
    double half=a*b/2;
    cout<<fixed<<setprecision(10);
    if(half>=x){
        double hight=x/b*2;
        cout<<90-(atan(hight/b)*180/PI)<<endl;
    }else{
        double hight=(a*b-x)*2/a;
        cout<<90-(atan(a/hight)*180/PI)<<endl;
    }
}