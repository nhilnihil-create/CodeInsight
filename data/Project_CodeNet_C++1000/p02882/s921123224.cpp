#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1e9+7

int main(){
    double a,b,x;
    double pi=3.14159265;
    cin >> a >> b >> x;
    x/=a;
    if(x*2<=a*b){
        //水が少ない
        cout << fixed << setprecision(8) << atan(b*b/(2*x))*180/pi << endl;
    }else{
        cout << fixed << setprecision(8) << abs(atan((x-a*b)*2/(a*a))*180/pi) << endl;
    }
}