#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int main() {
  string s;
  cin>>s;
  int n=s.size();
  vector<int64_t>a(n+1);
  for(int i=0;i<n;i++){
    if(s[i]=='<'){a[i+1]=a[i]+1;}
  }
  for(int i=n-1;i>=0;i--){
    if(s[i]=='>'){a[i]=max(a[i],a[i+1]+1);}
  }
  int64_t sum=0;
  for(int i=0;i<=n;i++){
    sum+=a[i];
  }
  cout<<sum<<endl;
  return 0;
}
