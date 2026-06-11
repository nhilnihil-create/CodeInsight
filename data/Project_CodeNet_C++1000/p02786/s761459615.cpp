#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
   ll H;
   cin >> H;
   ll cnt=0;
   while(H>0){
       H-=pow(2,cnt);
       cnt++;
   }
   
   
   ll ans;
   ans=pow(2,cnt)-1;
   cout << ans << endl;
}
