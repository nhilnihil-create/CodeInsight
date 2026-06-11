#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;


void solve(){
   int l, r, d;
   cin >> l >> r >> d;
   int s , c = 0;
   for(int i = 1; i <= r; i++){
       s = i * d;
       if(s >= l && s <= r){
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
