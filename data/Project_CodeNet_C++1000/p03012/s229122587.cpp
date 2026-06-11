#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> ans(n - 1);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for(int t = 1; t < n; t++){
    int sum1 = 0, sum2 = 0;
    for(int j = 0; j < n; j++){
      if(j + 1 <= t) sum1 += a[j];
      else sum2 += a[j];
    }
    ans[t - 1] = abs(sum1 - sum2);
  }
  cout << *min_element(ans.begin(),ans.end()) << endl;
}