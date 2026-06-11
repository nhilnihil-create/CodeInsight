#include <bits/stdc++.h>
using namespace std;

int main() {
  string a;
  cin >> a;
  string c;
  if(a == "ABC"){
    c="ARC";
  }
  if(a == "ARC"){
    c="ABC";
  }
  cout<<c<<endl;
	return 0;
}
