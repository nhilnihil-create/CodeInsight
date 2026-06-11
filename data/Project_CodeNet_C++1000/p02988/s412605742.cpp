#include <bits/stdc++.h>
using namespace std;
 
int n;
int a[25];
int res = 0;

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  for(int i = 1; i < n-1; ++i){
    if(a[i-1] < a[i]){
      if(a[i] < a[i+1]){
        res += 1;
      }
    }else{
      if(a[i] > a[i+1]){
        res += 1;
      }
    }
  }
  cout << res << endl;
}