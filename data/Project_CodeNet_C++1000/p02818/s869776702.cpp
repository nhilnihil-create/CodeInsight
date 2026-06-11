#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t a,b,x;
  cin >> a >> b >> x;
  if(x<a){
    cout << a-x << " " << b << endl;
  }else if(x<=a+b){
    cout << 0 << " " << a+b-x << endl;
  }else{
    cout << 0  << " " << 0 << endl;
  }
}
