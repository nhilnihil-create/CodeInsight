/**
 *    author: gxfireball       
**/
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
using namespace std;

void solve(){
   string str1,str2;
   cin>>str1>>str2;
   ll cnt=0;
   for(int i=0; i<str1.size(); ++i){
       if(str1[i] != str2[i]) cnt++;
   }
   cout<<cnt;

}

int main(){
    fastio;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    t = 1;
    //cin>>t;
    while(t--){
    	solve();
    }
    return 0;
}

