#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<long long>a(n);
  for(int i=0;i<n;i++){
    long long num;
    cin >> a.at(i);
    if(a.at(i)==0){
      cout << 0 << endl;
      return 0;
    }
  }
  long long x=1;
  long long m=1e18;
  for(int i=0;i<n;i++){
    if(a.at(i)>m/x){
      cout << -1 << endl;
      return 0;
    }
    x*=a.at(i);
  }
  cout << x << endl;
}
