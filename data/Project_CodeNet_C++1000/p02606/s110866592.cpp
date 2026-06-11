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
   int a,b,c;
   cin>>a>>b>>c;
   int cnt=0;
   for(int i=a;i<=b; ++i){
   	if(i%c == 0) cnt++;
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

