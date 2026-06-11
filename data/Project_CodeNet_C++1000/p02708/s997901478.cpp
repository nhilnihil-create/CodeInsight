#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;

ll num[200001] = {};

int main(){
    ll n, k, i, fact = 0;
    cin >> n >> k;
    for(i=0; i<n+1; i++){
        if(i==0) num[i] = n+1;
        else num[i] = num[i-1] + (i+1)*n - i*(i+1)+1;
        num[i] %= MOD;
    }
    cout << (num[n]-num[k-2]+MOD)%MOD;
    return 0;
}