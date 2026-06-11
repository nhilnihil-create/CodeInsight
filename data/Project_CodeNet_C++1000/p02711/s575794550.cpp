#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>> n;
  
  if(n%10 == 7){
    cout<< "Yes";
	  return 0;
  }
  n=n/10;
  if(n%10 == 7){
    cout<< "Yes";
	  return 0;
  }
  n=n/10;
  if(n%10 == 7){
    cout<< "Yes";
	  return 0;
  }
  cout<< "No";
  
	return 0;
}
