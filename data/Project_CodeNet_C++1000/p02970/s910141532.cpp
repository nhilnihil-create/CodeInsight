#include <bits/stdc++.h>
using namespace std;
int main(void){
   int a,b;
   cin >> a >> b;
   int c = 2*b+1;
   int d = a/c;
   if(a%c == 0) cout << d << endl;
   else cout << d+1 << endl;
    
}
