#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
   
   int A,V,B,W,T;
   cin >> A >> V >> B >> W >> T;

   if(W-V >= 0) cout << "NO" << endl;
   else{
       if((double)abs(A-B)/abs(W-V) <= T) cout << "YES" << endl;
       else cout << "NO" << endl;
   }
}