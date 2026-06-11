#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  	string L[] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    string S;
	cin >> S;
  
 	rep(i,7){
     if(S == L[i]){
     	cout << (7-i) << endl;
     }
    }
  return 0;
}
