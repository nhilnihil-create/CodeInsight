#include<bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define uset unordered_set<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, k, ans = 0, diff;
    cin >> n >> k;
    
    diff = n-k;
    ans = abs(diff)%k;
    ll temp = abs(ans - k);
    if(temp < ans){
        ans = abs(ans-k);
    }
    cout << ans << endl;
    return 0;
}