#include <bits/stdc++.h>
using namespace std;

long n, k;
double a[200005];

bool c(double m){
  long cnt = 0;
  for(int i=0; i<n; i++){
    cnt += (long)(a[i] / m);
    if((int)(a[i]/m)*m == a[i])  cnt--;
  }
  return cnt <= k;
}

int main(){
  cin >> n >> k;
  for(int i=0; i<n; i++)  cin >> a[i];
  
  double s = 0, t = 1e10;
  for(int i=0; i<1000; i++){
    double mid = (s + t) / 2.0;
    if(c(mid))  t = mid;
    else  s = mid;
  }

  long ans = (long)s;
  if(s - (long)s)  ans++;

  cout << ans << endl;

  return 0;
}
