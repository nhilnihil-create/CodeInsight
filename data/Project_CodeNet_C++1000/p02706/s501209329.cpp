#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
   int n,m,cnt=0,ans;
   cin >> n >> m ;

   int a[m];
   for(int i=0; i<m; i++){
       cin >> a[i] ;
       cnt += a[i];
   }
   
   if(cnt > n){
       ans = -1;
   }else{
       ans = n - cnt;
   }

   cout << ans << endl;

    return 0;
}