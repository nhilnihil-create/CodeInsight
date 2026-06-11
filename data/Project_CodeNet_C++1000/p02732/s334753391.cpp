#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n; cin >> n;
    vector<int> a(200000);
    vector<ll> memo(200000+1, 0);
    for(int i=0; i<n; i++){
        cin >> a[i];
        memo[a[i]]++;
    }
    ll sum=0;
    for(int i=1; i<=n; i++){
        if(memo[i]<2) continue;
        else{
            sum += memo[i]*(memo[i]-1)/2;
        }
    }
    for(int i=0; i<n; i++){
        ll ans = sum - (memo[a[i]]-1);
        cout <<ans << endl;
    }
    return 0;

}