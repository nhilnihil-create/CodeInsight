#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  //cout << n << endl;
  vector<int> w_i(n+1);
  for(int i=0;i<n;i++){
    cin >> w_i[i];
    //cout << w_i[i];
  }
  int a,b;
  int c=9901;
  for(int i=0;i<n;i++){
    a=0;b=0;
    for(int j=0;j<i+1;j++){
      a += w_i[j];
    }
    //cout << a << endl;
    for(int k=i+1;k<n;k++){
      b += w_i[k];
    
    }
    //cout << b << endl;
    if(abs(a-b)<c){
      c = abs(a-b);
    }
  }
  cout << c << endl;
 
}