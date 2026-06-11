#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  	
  	long long a,b;
  	cin >> a >> b;
  	if (a>=1 && b>=1 && a<=9 && b<=9){
      cout << a*b;
    }
  	else {
      cout << -1;
    }
}