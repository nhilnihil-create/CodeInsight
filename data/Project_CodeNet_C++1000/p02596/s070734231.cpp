#include <iostream>
#include <bits/stdc++.h>

#define rep(i,z) for(int i = 0; i<(int)(z); i++)
#define rep1(i,z) for(int i = 1; i<=(int)(z); i++)
 
using namespace std;

typedef long long ll;
const ll MOD=1e9+7;
using pear = pair<int,int>;

int main(){
   ll k; cin>>k;
   ll now  = 7 % k;
   rep(i,1e+6){
       if(now == 0) {
           cout<< i + 1 <<endl;
           return 0;
       }else now = (10 * now % k + 7 % k) % k; 
   }
   cout<< -1 <<endl;
}