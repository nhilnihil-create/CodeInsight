#include <iostream>
using namespace std;

int main() {
  int n; cin>>n;
  int a[n]; for(int i=0; i<n; i++) cin>>a[i];
  long long x=1000;
  int i=0;
  while(1){
    while(i<n-1&&a[i]>=a[i+1]) i++;
    if(i==n-1) break;
    long long s=x/a[i];
    x=x%a[i];
    while(i<n-1&&a[i]<=a[i+1]) i++;
    x=x+s*a[i];
  }
  cout<<x<<endl;
}

