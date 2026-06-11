#include<bits/stdc++.h>
using namespace std;

int main(){
  long long a, b, k;
  cin >> a >> b >> k;
  if(k <=a){
    cout << a-k << " " << b << endl;
  } else {
    cout << 0 << " " << max((long long)0,a+b-k) << endl;
  }
}