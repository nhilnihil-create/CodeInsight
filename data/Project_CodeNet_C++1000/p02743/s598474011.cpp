#include <bits/stdc++.h>
using namespace std;
 
int main(){
  long long a,b,c;
  cin >> a >> b >> c;
  if((c-a-b)*(c-a-b)==4*a*b) cout << "No" << endl;
  else if(c <= a+b) cout << "No" << endl;
  else if((c-a-b)*(c-a-b)>4*a*b) cout << "Yes" << endl;
  else cout << "No" << endl;
}