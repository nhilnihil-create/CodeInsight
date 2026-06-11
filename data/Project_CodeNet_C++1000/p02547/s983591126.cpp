#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  bool ok = false;
  int cnt = 0;
  for(int i=0; i<n; i++) {
    int d1, d2;
    cin >> d1 >> d2;
    if(d1 == d2) cnt++;
    else cnt = 0;
    
    if(cnt == 3) ok = true;
  }
  
  puts(ok?"Yes":"No");
}