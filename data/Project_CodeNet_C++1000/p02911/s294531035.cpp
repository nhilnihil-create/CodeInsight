#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  int n,k,q;cin >> n >> k >> q;
  int p[n];rep(i,n)p[i] = k;
  int a[q];
  rep(i,q) {
    cin >> a[i];
    p[a[i]-1] += 1;
  }
  rep(i,n){
    if(p[i] - q <= 0){
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
  return 0;
}
