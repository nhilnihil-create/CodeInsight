#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  ll n, a, b; cin >> n >> a >> b;
  ll dis = b-a;

  ll res = min(a-1, n-b);

  if(dis>1 && dis%2==0){
    cout << dis/2 << endl;
    return 0;
  }
  else{
    cout <<  res + 1 + (dis-1)/2 << endl;
  }

}