#include <bits/stdc++.h>
using namespace std;
int main() {
 int a;
  cin >> a;
  int b[a],sum=0,ans1=0,ans2=0;
  for(int i=0;i<a;i++){
    cin >> b[i];
    sum+=b[i];
  }
  sum /=a;
  for(int i = 0;i<a;i++) ans1 += (sum-b[i])*(sum-b[i]);
  sum++;
  for(int i = 0;i<a;i++) ans2 += (sum-b[i])*(sum-b[i]);
  cout << min(ans1,ans2);
}
