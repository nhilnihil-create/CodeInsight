#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  vector<int> ans;
  vector<bool> prime(246913,1);
  for(int i = 2;i <= 246912;i++){
    if(prime[i]){
      for(int j = 2 * i;j <= 246912;j += i){
        prime[j] = 0;
      }
    }
  }
  while(cin >> n,n){
    int count = 0;
    for(int i = n + 1;i <= 2*n;i++){
      if(prime[i])count++;
    }
    ans.push_back(count);
  }
  for(int i = 0;i < ans.size();i++)cout << ans[i] << endl;
}
