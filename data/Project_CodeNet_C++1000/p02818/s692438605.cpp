#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  long long int a,b,k;
  cin >> a >> b >> k;
  
  if(a<=k){
    k -= a;
    a = 0;
  }else{
    a -= k;
    cout << a << " " << b << endl;
    return 0;
  }
 
  if(b-k>0){
    b -= k;
  }else if(b-k==0){
    b = 0;
  }else{
    b = 0;
  }
  
  cout << a << " " << b << endl;
}