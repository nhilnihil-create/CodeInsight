#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;


void solve(){
   int n, c = 0;
   cin >> n;
   int a[n];
   for(int i = 1; i <= n; i++){
       cin >> a[i];
   }
   for(int i = 1; i <= n; i+=2){
       if(a[i] % 2 == 1){
           c++;
       }
   }
   cout << c << endl;

}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    solve();
    return 0;
}
