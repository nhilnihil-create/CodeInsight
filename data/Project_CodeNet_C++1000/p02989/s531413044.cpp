#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(int)(n);i++)
using ll = long long;
using P = pair<int, int>;
int main(){
  int n;
  cin >> n;
  int d[n];
  rep(i, n){
    cin >> d[i];
  }
  sort(d,d+n);
  if(d[n/2-1]==d[n/2]){
    cout << "0" << endl;
  } else {
    cout << d[n/2]-d[n/2-1] << endl;
  }
}
