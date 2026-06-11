#include <iostream>
#include <bits/stdc++.h>

#define rep(i,z) for(int i = 0; i<(int)(z); i++)
#define rep1(i,z) for(int i = 1; i<=(int)(z); i++)
 
using namespace std;

typedef long long ll;
const ll MOD=1e9+7;
using pear = pair<int,int>;



int main(){
   int n, m; cin>>n >>m;
   vector<int> ans(n);
   if(n > 1) ans[0] = 1;
   vector<bool> already(n);
   rep(i, n) already[i] = false;
   rep(i, m){
       int s, c; cin>>s >>c;
       s--;
        if(s == 0 && c == 0 && n > 1){
            cout<< -1 <<endl;
            return 0;
        }
       if(already[s] && ans[s] != c) {
           cout<< -1 <<endl;
           return 0;
        }else{
           
           already[s] = true;
           ans[s] = c;
       }
   }
   rep(i, n) cout<<ans[i];
   cout<<""<<endl;
}
