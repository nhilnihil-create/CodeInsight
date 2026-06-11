#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin>>n;
  vector<int>a(n);
  long long sum=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
  }
  long long sa=INT_MAX;
  long long sum2=0;
  for(int i=0;i<n;i++){
    sum2+=a[i];
    sa=min(sa,abs(abs(sum-sum2)-sum2));
  }
  cout<<sa<<endl;
  return 0;
}
    