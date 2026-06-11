#include<bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m, a, ans = 0, t, sum = 0;
    cin >> n >> m;
    vll x;
    
    for(ll i=0; i<n; i++){
        cin >> a;
        sum += a;
        x.push_back(a);
    }
    t = (sum-1)/(4*m) + 1;

    for(auto i:x){
        if(i >= t){
            ans += 1;
        }
    }
    
    if(ans < m){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
    return 0;
}