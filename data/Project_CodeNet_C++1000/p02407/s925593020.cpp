#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long ll;

int main(){
  int n, a[1001];

  cin>>n;
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  for(int j=n-1; j>=0; j--){
    if(j==0)cout<<a[j];
    else cout<<a[j]<<" ";
  }
  cout<<endl;
}