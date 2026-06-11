/**
 *    author: kalyan       
**/
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
using namespace std;
 
void solve(){
    int k,n;
    cin >> k >> n;
    if(k*500 >= n) cout <<"Yes";
    else cout <<"No";
    
}
 
int main(){
    fastio;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    t = 1;
    // cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}