#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,k;
  cin >> n >> k;
  vector<double>a(n);
  for(int i=0;i<n;i++){
    cin >> a[i]; 
  }
  double s=0;
  double u=0;
  for(int j=0;j<k;j++){
    u+=a[j];
  }
  for(int i=0;i<n-k+1;i++){
    if(s<u){
      s=u;
    }
    u+=a[i+k]-a[i];
  }
  cout << fixed << setprecision(10);
  cout << (s+k)/2 << endl;
}