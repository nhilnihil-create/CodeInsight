#include<iostream>
#include<vector>
using namespace std;

int main(){
  long long n,a,xsum=0,ans; cin >> n;
  vector<long long> vec;
  while(cin >> a){
    vec.push_back(a);
    xsum ^= a;
  }
  
  for(long long i = 0 ; i<n ; i++){
    ans = xsum^vec[i];
    cout<<ans<<" ";
  }
}
