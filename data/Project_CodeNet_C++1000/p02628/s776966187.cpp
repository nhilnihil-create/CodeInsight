#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k; cin >> n >> k;
  int arr[1000];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int s = 0;
  for(int i  = 0; i < k; i++)
    s += arr[i];
  
  cout << s << endl;
}
