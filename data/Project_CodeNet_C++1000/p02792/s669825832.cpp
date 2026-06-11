#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
ll mod = 1000000007;
ll inf = 1e18;
int main(){

    int n;
    cin >> n;
    vector<vector<ll>> num(10,vector<ll>(10));
    int k=1;
    rep(i,n+1){
        if(i==10*k) k*=10;
        num[i/k][i%10]++;
    }

    ll sum=0;
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++) sum+=num[i][j]*num[j][i];
    }

    cout << sum << endl;
    
    return 0;
}