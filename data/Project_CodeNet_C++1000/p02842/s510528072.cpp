#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int ans=n*100/108;
  if((double)ans<(double)n*100/108)ans++;
  if((int)ans*108/100==n)cout << ans << endl;
  else cout << ":(" << endl;
}