#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<map>



using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)


long long int n,m,k;
long long int x,y;
long long int mod = 1000000007;

long long int factorial(long long int n){
    long long int res;
    if (n == 0) return 1;
    res = (n%mod)*factorial(n-1)%mod;
    return res;
}

long long int f(long long int n, long long int m){
    long long int res;
    if(m == 1){
        return n;
    }
    if(m%2){
        res = n*f(n*n%mod, m/2)%mod;
    }
    else{
        res = f(n*n%mod, m/2)%mod;
    }
    return res;
}

int main(){
    cin >> x >> y;
    if((x+y) % 3 != 0 || 2*x-y < 0 || 2*y - x < 0) {
        cout << 0 << endl;
        return 0;
    }
    n = (2*x - y)/3;
    m = (2*y - x)/3;

    long long int nf, mf, nmf, nr, mr;
    nf = factorial(n);
    // cout << n << " " << nf << endl;
    mf = factorial(m);
    nmf = factorial(n+m);
    nr = f(nf,mod-2);
    mr = f(mf,mod-2);
    long long int ans;
    ans = (nr%mod)*(mr%mod);
    ans = (ans%mod)*(nmf%mod)%mod;
    cout << ans << endl;

    return 0;
}