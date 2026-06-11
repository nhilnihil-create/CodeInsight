#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int  main(){
  ll h, w;
  cin >> h >> w;
  
  if(h==1 || w==1){
    cout << 1 << endl;
    return 0;
  }
  ll masu = h*w;
  ll res = masu / 2;

  cout << masu - res << endl;
  return 0;
}