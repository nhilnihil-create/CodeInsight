#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
  int a;
  cin >> a;
  int sum=0,num[a],ans=0;
  for(int i = 0;i<a;i++){
    cin >> num[i];
    sum += num[i];
  }
  for(int i = 0;i<a;i++){
    sum -= num[i];
    ans += sum*num[i];
  }
  cout << ans;
}