#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  double tmp, ans=0;
  for(int i=0;i<n;i++){
    cin >> tmp;
    ans += 1/tmp;
  }
  cout << setprecision(15) << 1/ans << endl;
}