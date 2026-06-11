#include <bits/stdc++.h>
using namespace std;
//解説AC　難しい
int main(){
  int n;
  cin>>n;
  long long sum=0;
  long long sum2=0;
  vector<int>a(n),b(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
    if(i%2==1)sum2+=a[i];
  }
  b[0]=sum-2*sum2;
  for(int i=1;i<n;i++){
    b[i]=2*a[i-1]-b[i-1];
  }
  for(int i=0;i<n;i++){
    cout<<b[i]<<" ";
  }
  cout<<endl;
  return 0;
}