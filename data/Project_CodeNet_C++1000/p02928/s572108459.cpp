#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<list>

#define endl "\n"
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main(){
    int n;
    ll k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    ll ans = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n;j++){
            if(a[i] > a[j]) ans = (ans+1) %MOD;
        }
    }
    ans = ans * k %MOD;

    ll ten = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i] > a[j]) ten = (ten+1) %MOD;
        }
    }
    ans = ( ans + ten * ( k*(k-1)/2 %MOD ) ) %MOD;

    cout<< ans % MOD <<endl;
}