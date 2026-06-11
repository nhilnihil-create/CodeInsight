#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  int ans = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  int saishou = a[0];
  for(int i = 0; i < n; i++){
    saishou = min(a[i], saishou);
    if(a[i] == saishou){
      ans++;
    }
  }
  cout << ans << endl;
}