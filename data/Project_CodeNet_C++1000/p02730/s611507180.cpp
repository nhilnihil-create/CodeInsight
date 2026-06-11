// Hail god Yato
 
#include <bits/stdc++.h> 
using namespace std;
 
#define hs ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll mod = 1000000007;
const ll INF = 1e18;
const ll MAX = 100001;
//
//
bool check(string str){
    int n = str.length();
    for(int i = 0; i < n; i++)
        if(str[i] != str[n-1-i])
            return false;
    return true;
}
void solve(){
    string str;
    cin>>str;
    int n = str.length();
    if(check(str) && check(str.substr(0, n/2)) && check(str.substr((n+1)/2)))
        cout<<"Yes";
    else
        cout<<"No";
    
}
int main(){ 
        hs;
        ll t;
        t=1;
        // cin>>t;
        for (int i=1; i<=t; i++){
                //cout<<"Case #"<<i<<": ";
                solve();
         }
        return 0; 
}