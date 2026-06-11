#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  int n;
  cin>>n;
  long long sum=0;
  for(int i=1;i<n;i++){
    sum+=i;
  }
  cout<<sum<<endl;
  return 0;
}