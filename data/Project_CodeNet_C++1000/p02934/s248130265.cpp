#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  	
  	double a,c=0;
  	cin >> a;
  	for (int i=0; i<a; i++) {
      double b;
      cin >> b;
      c+=1/b;
    }
  	cout << 1/c;
      
}