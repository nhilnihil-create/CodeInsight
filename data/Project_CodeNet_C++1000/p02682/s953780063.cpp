#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t a,b,c;
  cin >> a >> b >> c;
  int64_t  k;
  cin >> k;
  if(k<=a)cout << k << endl;
  else if(k<=a+b)cout << a << endl;
  else if(k<=a+b+c)cout << a-(k-a-b) << endl;
}
