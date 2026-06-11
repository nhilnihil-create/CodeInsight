/**
 *    author: gxfireball       
**/
#include <bits/stdc++.h>
#include <math.h>
#define ll long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
using namespace std;

void solve(){
   int n;
   cin>>n;
   int cnt=0;
   for(int i=1;i<=n; ++i){
   	int temp;cin>>temp;
   	if(i&1 && temp&1) cnt++;
   }
   cout<<cnt;
   


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

