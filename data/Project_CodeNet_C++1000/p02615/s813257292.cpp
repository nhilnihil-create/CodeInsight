#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n;
  cin>>n;
  vector<long long> vec(n);
  for(long long i=0;i<n;i++){
    cin>>vec.at(i);
  }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  if(n==2){
    cout<<vec.at(0)<<endl;
    return 0;
  }
  if(n==3){
    cout<<vec.at(0)+vec.at(1)<<endl;
    return 0;
  }
  long long ans=vec.at(0);
  long long i=2;
  long long j=1;
  
  while(i<n){
    ans+=vec.at(j);
    i++;
    
    if(i%2==0){
      j++;
    }
  
  }
  cout<<ans<<endl;
}
