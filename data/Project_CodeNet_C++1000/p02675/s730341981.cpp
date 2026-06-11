#include <bits/stdc++.h>
 using namespace std;

int main(){
  long long N,i,j;
  cin >> N;

  string res;
  switch(N % 10){
    case 0:
    case 1:
    case 6:
    case 8:
      res = "pon";
      break;
    case 3:
      res = "bon";
      break;
    default:
      res = "hon";
  	  break;
  }

  cout << res << endl;
}