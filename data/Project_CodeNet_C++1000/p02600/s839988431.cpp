#include<bits/stdc++.h>
using namespace std;
int main(){
  int a;
  cin >> a;
  if(400<=a && a<=599)cout << 8 << endl;
    if(600<=a && a<=799)cout << 7 << endl;
    if(800<=a && a<=999)cout << 6 << endl;  
    if(1000<=a && a<=1199)cout << 5 << endl;
    if(1200<=a && a<=1399)cout << 4 << endl;
      if(1400<=a && a<=1599)cout << 3 << endl;
      if(1600<=a && a<=1799)cout << 2 << endl;
      if(1800<=a && a<=1999)cout << 1 << endl;
}