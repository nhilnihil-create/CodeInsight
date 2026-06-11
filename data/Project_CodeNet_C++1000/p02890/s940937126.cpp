#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    int A;
    cin >> A;
    A--;
    a[A]++;
  }

  sort(a.begin(),a.end());
  vector<int> sum;
  sum = a;

 

  for(int i = 1; i < a.size(); i++) {
    sum[i] += sum[i-1];
  }

 
  for(ll i = 1; i <= n; i++) {
    ll l = 0, r = n + 1;
   
    while(r - l > 1) {
      ll mid = (l + r) / 2;
      ll tmp = upper_bound(a.begin(),a.end(),mid) - a.begin();
      ll x = sum[tmp-1];
      ll y = (a.size() - tmp) * mid;
      //  cout <<"mid = "<<  mid <<"   tmp = "<< tmp <<"   x+y = "<<x+y<< endl;
      if(x + y >= mid * i) l = mid;
      else r = mid;
    }

     cout << l << endl;
  }
}






      
