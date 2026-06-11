#include<bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define uset unordered_set<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, b, ans = 0;
    cin >> n >> b;
    
    while(n > 0){
        ans += 1;
        n = n/b;
    }
    
    cout << ans << endl;
    return 0;
}