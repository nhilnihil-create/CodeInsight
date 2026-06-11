#include <bits/stdc++.h>
using namespace std;

int main(){
  
  long long h,w;
  cin >> h >> w;
  long long a=h*w;
  if(h==1 || w==1){
    cout << 1 << endl;
  }
  else if(a%2==0) cout << a/2 << endl;
  else cout << (a-1)/2+1 << endl;
}
