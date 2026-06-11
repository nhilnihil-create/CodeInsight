#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vll vector<ll>
using namespace std;
 
 
int main(){
    ios_base::sync_with_stdio(true);
    cin.tie(NULL);
    
    ll n, ans = 1, a;
    cin >> n;
    vll x;
    for(ll i=0; i<n; i++){
        cin >> a;
        x.push_back(a);
    }
    ll mini = x[0];
    for(ll i=1; i<n; i++){
        mini = min(x[i-1], mini);
        //cout << mini << " " << x[i] << endl;
        if(mini > x[i]){
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}