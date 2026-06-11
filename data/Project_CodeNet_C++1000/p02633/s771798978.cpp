#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int k;
  for(int i=1;;i++){
    k=n*i;
    if(k%360==0){
      cout << i << endl;
      break;
    }
  }
}
