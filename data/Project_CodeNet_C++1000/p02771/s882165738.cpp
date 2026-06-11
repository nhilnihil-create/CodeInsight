#include<bits/stdc++.h>
using namespace std;
int main(void)
{
  int a,b,c;
  cin >> a >> b >> c;
  if((a==b&&b==c)||(a!=b&&b!=c&&c!=a)){
    puts("No");
  } else {
    puts("Yes");
  }
}
