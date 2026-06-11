#include<bits/stdc++.h>
using namespace std;

int main(){
  long long a,b,k;
  cin >> a >> b >> k;
  if(a == 0 && b == 0){
    cout << 0 << " " << 0 << endl;
  }else if(a - k <= 0 && (k - a) <= b){
    cout << 0 << " " << (b-(k-a)>=0 ? b - (k - a):0) << endl;
  }else if(a - k <= 0 && (k - a) >= b){
    cout << 0 << " " << (b-(k-a)>=0 ? b - (k - a):0) << endl;
  }else if(a - k >= 0){
    cout << a - k << " " << b << endl;
  }
}