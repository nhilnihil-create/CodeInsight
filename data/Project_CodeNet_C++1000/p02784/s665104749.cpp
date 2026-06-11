#include <bits/stdc++.h>
using namespace std;

int main() {
  long long h,n;cin>>h>>n;
  vector<int>vec(n);long long sum=0;
  for(int i=0;i<n;i++){
    cin>>vec.at(i);
    sum+=vec.at(i);
  }
  if(h>sum)cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
}
