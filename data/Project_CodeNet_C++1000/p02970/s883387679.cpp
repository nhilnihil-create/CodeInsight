#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int n,d;
  cin >> n >> d;
  d *=2;
  d += 1;
  if(n%d==0){
    cout << n/d << endl;
  } else {
    cout << n/d+1 << endl;
  }
}