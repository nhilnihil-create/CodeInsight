#include <bits/stdc++.h>
using namespace std;
 
int a, b, c, d, hasil;
 
int main () {
cin >> a >> b >> c;
d=a-b;
if ((d>c)||(d==c)) {
     hasil=0;
     cout << hasil << endl;
 
}else{
     hasil=c-d;
     cout << hasil << endl;
}
}