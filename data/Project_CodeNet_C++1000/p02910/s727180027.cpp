#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  	
  	string a;
  	cin >> a;
  	long long b=a.length(), d=0;
  	for (int i=0; i<b; i++) {
      char c=a[i];
      if (i%2==0){
        if (c!='R' && c!='U' && c!='D'){
          break;}
        else {
          d++;}
      	}
      else{
        if (c!='L' && c!='U' && c!='D'){
          break;}
        else {
          d++;}
      	}
      }
  if (d==b) {
    cout << "Yes";
  }
  else {
    cout << "No";
  }
}