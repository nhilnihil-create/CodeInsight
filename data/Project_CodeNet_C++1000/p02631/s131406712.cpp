#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)	for(int i=0;i<n;i++)

int main(){
  int n;	cin >> n;
  vector<long long>	a(n);
  rep(i,n)	cin >> a[i];
  
  long long b;
  b=a[0];
  for(int i=1;i<n;i++){
    b^=a[i];
  }
  
  rep(i,n){
    long long x=a[i]^b;
    cout << x << endl;
  }
  
}