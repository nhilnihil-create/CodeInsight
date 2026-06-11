#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  long long sum = 0;
  int p = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
  }
  for(int i = 0; i < n; i++){
    if( a[i] * 4 * m >= sum ) p++;
  }
  cout << ( p >= m ? "Yes" : "No" ) << endl;
}