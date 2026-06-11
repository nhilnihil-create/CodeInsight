/**
 *    author: kalyan       
**/
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
using namespace std;
 
void solve(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    int cnt=0;
    for(int i =0;i<=n-3; ++i){
        if(str.substr(i,3) == "ABC") cnt++;
    }
    cout << cnt;
    
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