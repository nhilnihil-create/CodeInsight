#include<iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;

  long long  a[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  int zero=0;
  for(int i=0;i<n;i++){
    if(a[i]==0) zero++;
  }

  if(zero>0){
    cout << 0;
    return 0;
  }
  else{
    long long ans = 1;
    for(int i=0;i<n;i++){
      if(a[i]<=1000000000000000000/ans){
        ans *= a[i];
      }
      else{
        ans = -1;
        break;
      }
    }

    cout << ans;
  }

  return 0;
}