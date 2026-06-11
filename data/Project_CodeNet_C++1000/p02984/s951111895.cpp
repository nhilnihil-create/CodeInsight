#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P  = pair<int,int>;
using v  = vector<int>;
using vv = vector<v>;
const int MOD = 1000000007;

int main(){
    int n;
    cin >> n;
    
    int k = n/2;
    
    vector<ll> a(n+1);
    ll sum = 0;
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
        sum += a[i];
    }
    
    sum /= 2;
    vector<ll> d(n+1,0);
    
    for(int i=1; i<=k; i++){
        d[1] += a[2*i];
    }
    
    for(int i=3; i<=n; i+=2){
        d[i] = d[i-2] + a[i-2] - a[i-1];
    }
    
    d[2] = d[n] + a[n] - a[1];
    
    for(int i=4; i<n; i+=2){
        d[i] = d[i-2] + a[i-2] - a[i-1];
        
    }
    
    for(int i=1; i<=n; i++){
        //cout << d[i];
        cout << 2*(sum - d[i]);
        if(i!=n)cout << " ";
        else cout << endl;
    }
    
    return 0;
}