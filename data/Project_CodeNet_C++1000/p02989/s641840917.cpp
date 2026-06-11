#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  int d[n];
  rep(i,n)cin >> d[i];

  sort(d,d+n);
  if(d[n/2-1]==d[n/2]){
    cout << 0 << endl;
    return 0;
  }else{
    cout << d[n/2]-d[n/2-1] << endl;
    return 0;
  }
}