#include <bits/stdc++.h>
using namespace std;
int main(){
   int a,b;
   int p,q;
   int c;
   cin >> a >> b;
   vector<bool> v(a,true);
   for(int i=0;i<b;i++){
       int A;
       cin >> A;
       v[A-1] = false;
   }
   if(a == 1){
       if(v[0])cout << 1 << endl;
       else cout << 0 << endl;
   }
   else{
       if(v[0])p = 1;
        else p = 0;
        if(v[1])q = p + 1;
        else q = 0;
        for(int i=2;i<a;i++){
            if(v[i]){
                c = q;
                q += p;
                p = c;
                p %= 1000000007;
                q %= 1000000007;
            }else{
                p = q;
                q = 0;
            }
        }
   cout <<q << endl;
   }
 }