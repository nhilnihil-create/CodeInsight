#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, m; cin >> n >> m;
    vector<ll> routes(n+1, 1);
    set<int> danger;
    for(int i=0; i<m; i++){
        int d; cin>>d;
        danger.insert(d);
    }
    ll mod = 1000000007;
    for(int i=1; i<=n; i++){
        if(danger.find(i)!=danger.end()) routes[i]=0;
        else{
            if(i==1) continue;
            else routes[i] = (routes[i-1] + routes[i-2]) % mod;
        } 
    }
    cout << routes[n] << endl;
}