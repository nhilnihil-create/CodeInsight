#include <bits/stdc++.h>
using namespace std;

int main() {
int64_t n,a;
  a=0;
  cin>>n;
vector<int64_t> vec(n);
  vector<int64_t> ans(n);
  for(int64_t i=0;i<n;i++){
  cin>>vec.at(i);
  }
  for(int64_t i=0;i<n;i++){
 ans.at(vec.at(i)-1)++;
  }
  for(int64_t i=0;i<n;i++){
  a=a+ans.at(i)*(ans.at(i)-1)/2;
  }
  for(int64_t i=0;i<n;i++){
  cout<<a-ans.at(vec.at(i)-1)+1<<endl;
  }
}
