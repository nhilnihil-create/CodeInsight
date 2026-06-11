#include<bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
int main(){
 int n,x,t;
 int ans = 0;
 cin >> n >> x >> t;
 while(n>0){
     n -= x;
     ans+=t;
 }
 cout << ans << endl;
 return 0;
}