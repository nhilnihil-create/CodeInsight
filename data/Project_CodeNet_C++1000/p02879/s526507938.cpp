#include <bits/stdc++.h>
using namespace std;

int a, b, hasil;

int main () {
cin >> a >> b;
if ((0<a)&&(0<b)&&(10>a)&&(10>b)) {
     hasil=a*b;
     cout << hasil << endl;
} else {
     hasil=-1;
     cout << hasil << endl;
}
}
