#include<iostream>
#include<vector>
using namespace std;
#define ll long long
const int MAX=1e6;
const int MOD=1e9+7;
vector<ll> fact(MAX),inv(MAX),finv(MAX);
int X,Y;

void COMinit(){
    fact[0]=fact[1]=1;
    inv[1]=1;
    finv[0]=finv[1]=1;
    for(int i=2;i<MAX;i++){
        fact[i]=fact[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}

ll COM(int n,int k){
    if(n<0||k<0||n<k) return 0;
    return fact[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

ll solve(int X,int Y){
    if(2*Y-X<0||2*X-Y<0) return 0;
    if((2*Y-X)%3!=0||(2*X-Y)%3!=0) return 0;
    int N=(2*Y-X)/3;
    int M=(2*X-Y)/3;
    return COM(N+M,N);
}

int main(){
    COMinit();
    cin>>X>>Y;
    cout<<solve(X,Y)<<endl;
    return 0;
}