#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int  main(){
  int n;
  cin >> n;

  if(ceil(n/1.08) < ceil((n+1) / 1.08)){
    cout << ceil(n/1.08) << endl;
    return 0;
  }

  cout << ":(" << endl;

  return 0;
}