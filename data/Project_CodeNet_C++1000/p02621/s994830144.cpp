/**
 *    author: gxfireball       
**/
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
using namespace std;

void solve(){
   int a;
  	cin>>a;
 
   ll ans = pow(a,2) + pow(a,3) + a;
   cout<<ans;

}

int main(){
    fastio;
    int t;
    t = 1;
    //cin>>t;
    while(t--){
    	solve();
    }
    return 0;
}

