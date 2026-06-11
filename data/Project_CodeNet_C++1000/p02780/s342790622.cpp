#include<bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main(){
  int64_t n,k;
  cin >>n>>k;
  int64_t ans=0;
  vector<int64_t>a(n+1,0);
  int64_t tmp;
  for(int i=0;i<n;i++){
    cin >>tmp;
    a.at(i+1)=a.at(i)+tmp+1;
  }
  for(int i=k;i<n+1;i++){
    ans=max(ans,a.at(i)-a.at(i-k));
  }
  cout << fixed << setprecision(19)<<(double)(ans)/2<<endl;
}