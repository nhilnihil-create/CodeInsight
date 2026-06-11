#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll a,b;
  cin >> a >> b;
  
  if(a==1||b==1){
    cout << 1 << endl;
  }
  else if(a*b%2==0){
    cout << a*b/2 << endl;
  }
  else if(a*b%2!=0){
    cout << a*b/2+1 << endl;
  }
}