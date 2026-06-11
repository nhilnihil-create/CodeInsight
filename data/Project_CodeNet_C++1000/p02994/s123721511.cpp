#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

int main(){
  int n, l;
  cin >> n >> l;

  vector<int> a(n);
  int sum = 0;
  int cp_l = l;
  int mn = 101, mx = -101;
  bool flag = false;

  for(int i=0; i<n; ++i){
    if(cp_l==0) flag =true;
    a[i] = cp_l;
    sum += a[i];
    mn = min(mn, a[i]);
    mx = max(mx, a[i]);
    ++cp_l;
  }

  if(flag){
    cout << sum;
    return 0;
  }
  
  if(sum>=0) cout << sum -mn;
  else cout << sum - mx;

  return 0;
}