#include <bits/stdc++.h>
using namespace std;
int main()
{
 int a,b,c,t;
 c=0;
 t=1;
 cin >> a >> b;
 while(t<b)
 {
  t--;
  t+=a;
  c++;
 }
 cout << c;
 return 0;
}