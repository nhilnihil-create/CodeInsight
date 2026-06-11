#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long n=0;
  long long ans=0;
  cin>>n;
  for(int i=0;i<n;i++){
    if((i+1)%3!=0&&(i+1)%5!=0){
      ans=ans+i+1;
    }
  }
  cout<<ans;
}