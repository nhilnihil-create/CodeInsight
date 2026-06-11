#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int count[n];
  int a[n];
  for(int i = 0; i < n; i++) count[i] = 0;
  for(int i = 0; i < n - 1; i++){
    cin >> a[i];
  }
  for(int i = 0; i < n - 1; i++){
    count[a[i] - 1]++;
  }
  for(int i = 0; i < n; i++){
    cout << count[i] << endl;
  }
}