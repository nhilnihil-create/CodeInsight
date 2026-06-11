#include<bits/stdc++.h>
using namespace std;
 
signed main()
{
  string n; cin >> n;
  string a = n.substr(n.length() -1);
  if(a=="2"||a=="4"||a=="5"||a=="7"||a=="9") {cout << "hon";}
  if(a=="0"||a=="1"||a=="6"||a=="8") {cout << "pon";}
  if(a=="3") {cout << "bon";}
}