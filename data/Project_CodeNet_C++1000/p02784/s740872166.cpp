#include<bits/stdc++.h>
using namespace std;
int main(){
  long h,n; cin >> h >> n;
  long sum = 0;
  for(int i = 0; i < n; i++){
    long a; cin >> a;
    sum += a;
  }
  if(h - sum <= 0)
    cout << "Yes";
  else
    cout << "No";
}
  