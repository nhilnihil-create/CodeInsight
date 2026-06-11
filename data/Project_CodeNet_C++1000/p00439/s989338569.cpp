#include<iostream>
#include<algorithm>
using namespace std;

int main(){

  int n,k;

  while(cin >> n >> k, n, k){

    int a[100000] = {0},z = 0,x = 0;

    for(int i=0;i<n;i++) cin >> a[i];

    for(int i=0;i<k;i++) z += a[i];
    x = z;
    for(int i=k;i<n;i++){
      x += (a[i] - a[i-k]);
      z = max(z , x);
    }

    cout << z << endl; 
  }
}