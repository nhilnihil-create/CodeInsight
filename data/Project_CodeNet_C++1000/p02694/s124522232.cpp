#include <bits/stdc++.h>
using namespace std;
int main(){
  long long  x; cin >> x;
  long long i =100ll;
  int cnt = 0;
  while(1){
    if(i >= x){
      cout << cnt << endl;
      return 0;
    }
    cnt ++;
    i += i /100;;
  }
}
