#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second
using namespace std;
typedef pair <int,int> ii;
const ll MOD=1e9+7;
ll luythua(ll x,int y){
    if(y==0)return 1;
    ll k=luythua(x,y/2);
    return k*k%MOD*(y%2?x:1)%MOD;
}
ll C(int n,int k){
    if(n-k<k)k=n-k;
    ll res=1;
    for(int i=0;i<k;i++){
        res=res*(n-i)%MOD;
        res=res*luythua(i+1,MOD-2)%MOD;
    }
    return res;
}
int main() {
    int x,y;
    cin >> x >> y;
    if ((x+y)%3!=0||min(x,y)*2<max(x,y)) cout << 0;
    else {
        int k=abs(x-y);
        int bao = (x+y)/3;
        int hung=(bao-k)/2;
        cout<<C(bao,hung);
    }
}
