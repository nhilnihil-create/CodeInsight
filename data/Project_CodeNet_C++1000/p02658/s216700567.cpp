#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
  long long n,mul=1;
  cin>>n;
  vector<long long> a(n);
  for(int i=0;i<n;++i) {
    cin>>a[i];
    if (a[i]==0) {
      cout<<0<<endl;
      return 0;
    }
  }
  for(int i=0;i<n;++i) {
    if(a[i]>1000000000000000000LL/mul) {
      cout<<-1<<endl;
      return 0;
    }
    mul*=a[i];
  }
  cout<<mul<<endl;
}