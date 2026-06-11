#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  int m = *max_element(a.begin(), a.end());
  vector<int> b(n);
  copy(a.begin(), a.end(), b.begin());
  sort(b.begin(), b.end());
  int l = b[n - 2];
  for(int i = 0; i < n; i++){
    if(a[i] != m){
      cout << m << endl;
    }else{
      cout << l << endl;
    }
  }
}