#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  int a[n+1] = {};
  int ans = 0;
  for(int i = 0; i < k; i++){
    int d;
    cin >> d;
    for(int j = 0; j < d; j++){
      int p;
      cin >> p;
      a[p-1] = 1;
    }
  }
  for(int i = 0; i < n; i++){
    if(a[i]==0){
      ans++;
    }
  }
  cout << ans << endl;
}