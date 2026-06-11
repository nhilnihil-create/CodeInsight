#include <bits/stdc++.h>
using namespace std;

bool check(vector<long> a, int c, long k){
  long tmp=0;
  for(int i=0;i<a.size();i++){
    if(a[i]<=c)continue;
    tmp+= a[i]/c;
    if(a[i]%c==0)tmp--;
    // cout << tmp << endl;
  }
  if(tmp<=k) return true;
  else  return false;
}

int main() {
  int n;
  long k;
  cin >> n >> k;

  vector<long> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  int l=0;
  int r=1000000000;
  while(r-l>1){
    int c = (l+r)/2;
    if(check(a,c,k)){
      // cout << c << " yes" << endl;
      r=c;
    } else {
      // cout << c << " no" << endl;
      l=c;
    }
  }

  cout << r << endl;
  return 0;
}
