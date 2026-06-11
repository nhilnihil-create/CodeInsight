#include<iostream>
#include<vector>
using namespace std;
void f(long long n,vector<long long>& v){
  v.push_back(n);
  for(long long i=2;i*i<=n;i++){
    if(n%i==0){
      v.push_back(i);
      if(n!=i*i) v.push_back(n/i);
    }
  }
}
int main(){
  long long n;cin>>n;
  if(n==2){
    cout<<1<<endl;
    return 0;
  }
  vector<long long> s1,s2;
  long long c=0;
  f(n-1,s1);c+=s1.size();
  f(n,s2);
  for(auto a:s2){
    long long nn=n;
    while(nn%a==0) nn/=a;
    if(nn%a==1) c++;
  }
  cout<<c<<endl;
  return 0;
}
