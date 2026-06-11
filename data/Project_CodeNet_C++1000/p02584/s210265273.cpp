//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
int main(){
    
    
    long long int x,k,d,p;
    cin >> x >> k >> d;
    x = abs(x);
    if(x/d >= k) cout << abs(x - (k*d)) << endl;
    else{ 
          p = x%d;
          k = k - (x/d);
          if(k%2 == 0) cout << p << endl;
          else{
               cout << abs(p-d) << endl;
          }
    }
    return 0;
}