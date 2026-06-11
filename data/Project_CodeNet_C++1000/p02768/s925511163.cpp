#include <iostream>

#define modes 1000000007
using namespace std;

long long kuri2j(int n,long long x){//n^x mod modesを求める関数
    if(x==0) return (long long)1;
    if(x%2){
        return (n*kuri2j(n,x-1))%modes;
    } else {
        long long ll= kuri2j(n,x/2);
        return (ll*ll)%modes;
    }
}

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    // 2^n-1を求める
    long long ans= kuri2j(2,n)-1;
    long long nCa=1,Y=1;
    for(int i=0; i<a; i++) nCa = (nCa*(n-i))%modes;
    for(int i=1; i<=a;i++) Y = (Y*i)%modes;
    nCa = (nCa*kuri2j(Y,modes-2))%modes;
    ans -= nCa;
    if(a+b==n){
        ans -= nCa;
    } else {
        long long nCb=1,X=1;
        for(int i=0; i<b; i++) nCb = (nCb*(n-i))%modes;
        for(int i=1; i<=b;i++) X = (X*i)%modes;
        nCb = (nCb*kuri2j(X,modes-2))%modes;
        ans -= nCb;
    }
    if(ans < 0) ans = ans%modes + modes;
    cout << ans << endl;
}
