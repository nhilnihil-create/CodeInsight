#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a,b;
  cin >> a >> b;
  
  int ans = 0;
  int con = 1;
  while(con < b){
    con--;
    con += a;
    ans++;
  }
  
  cout << ans << endl;
}